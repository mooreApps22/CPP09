#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include "data.hpp" 


void	mergeInsertionSort(List& numbers) // numbers is the main chain
{
	Deque	deck;
	ListIt	it = numbers.begin();	

	while (it != numbers.end())
	{
		ListIt	first = *it;

		++it;
		if (it != numbers.end())
		{
			ListIt	second = *it;

			++it;	
			if (first > second)
			{
				numbers.push_back(first); // does this copy or move first?
				deck.push_back(second);
			}
			else
			{
				numbers.push_back(second); // does this copy or move first?
				deck.push_back(first);
			}
		}
		else
		{
			numbers.push_back(first);
		}
	}

	// Recursion  Alert!
	mergeInsertionSort(numbers);

	
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Usage: ./PmergeMe 1 33 44 ..." << std::endl;
		return (1);
	}

	List	numbers;
	
	numbers = fillList(argv);

	std::cout << "Before sorting: " << std::endl;
	std::cout << numbers;
	
	mergeInsertionSort(numbers); // Ford Johnson Sort Algorithm

	std::cout << "After sorting: " << std::endl;
	std::cout << numbers;

	return (0);
}

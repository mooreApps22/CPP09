#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include "data.hpp" 

void	mergeInsertionSort(List& numbers)
{
	if (numbers.size() <= 1)
		return ;
	
	List	mainChain;
	Deque	pend;
	ListIt	it = numbers.begin();

	// Compare pairs
	while (it != numbers.end())
	{
		int first = *it;

		++it;
		if (it != numbers.end())
		{
			int second = *it;

			++it;
			if (first > second) 
			{
				mainChain.push_back(first);
				pend.push_back(second);
			}
			else
			{
				mainChain.push_back(second);
				pend.push_back(first);
			}
		}
		else
		{
			mainChain.push_back(first);
		}

	}
	//  Recursion Alert!!
	mergeInsertionSort(mainChain);
	// Binary insert each elm into sorted mainChain
	for (DequeIt pIt = pend.begin(); pIt != pend.end(); ++pIt)
	{
		int value = *pIt;

		ListIt	low = mainChain.begin();
		ListIt	high = mainChain.end();
		// Binary search of insert point
		while (low != high)
		{
			ListIt	mid = low;

			std::advance(mid, std::distance(low, high) / 2);
			if (*mid < value)
				low = ++mid;
			else
				high = mid;
		}
		mainChain.insert(low, value);
	}
	// replace O.G.
	numbers = mainChain;
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

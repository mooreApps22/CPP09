#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
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

//		ListIt	low = mainChain.begin();
		ListIt	low = std::lower_bound(mainChain.begin(), mainChain.end(), value);
//		ListIt	high = mainChain.end();
		mainChain.insert(low, value);
		// Binary search of insert point
		/*
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
		*/
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
	std::cout << "List Size: " << numbers.size() << std::endl;

	std::cout << "Before sorting: " << std::endl;
	std::cout << numbers;
	
	double start = getTimeMicroseconds();
	mergeInsertionSort(numbers); // Ford Johnson Sort Algorithm
	double end = getTimeMicroseconds();

	std::cout << "After sorting: " << std::endl;
	std::cout << numbers;
	std::cout << std::fixed << std::setprecision(5);
	printTime("std::list", end - start, numbers.size());

	return (0);
}

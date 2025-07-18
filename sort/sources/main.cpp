#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
#include "data.hpp" 

void	mergeInsertionSort(List& numbers)
{
	
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

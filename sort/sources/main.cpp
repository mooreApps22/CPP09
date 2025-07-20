#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
#include "data.hpp" 
#include "MergeInsertionSorter.hpp" 

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Usage: ./PmergeMe 1 33 44 ..." << std::endl;
		return (1);
	}

	Deque	input;
	
	input = fillDeque(argv);
	std::cout << "Deque Size: " << input.size() << std::endl;

	MergeInsertionSorter	sorter;

	sorter.loadInput(input);

	std::cout << "Before sorting: " << std::endl;
//	std::cout << input;
	
	double start = getTimeMicroseconds();
	sorter.sort(); // Ford Johnson Algorithm
	double end = getTimeMicroseconds();

	std::cout << "After sorting: " << std::endl;
	std::cout << sorter.getDeque();
	std::cout << std::fixed << std::setprecision(5);
	printTime("std::deque", end - start, sorter.getDeque().size());
	return (0);
}

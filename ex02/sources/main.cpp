#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>
#include <sys/time.h>
#include "data.hpp" 

bool	validateArgCount(int argc)
{
	if (argc <= 2)	
	{
		std::cerr << "Usage: ./PmergeMe 233 21 12 ... " << std::endl;
		return (false);
	}
	return (true);	
}

double	getTimeInUsec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1e6 + tv.tv_usec;
}

int	main(int argc, char** argv)
{
	if (!validateArgCount(argc))
		return (1);
	Vector	inputVector;
	List	inputList;

	try
	{
		inputVector = loadContainer<Vector>(argc, argv);
		std::cout << "Before: ";
		printContainer(std::cout, inputVector);
		inputList = loadContainer<List>(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception Caught: " << e.what() << std::endl;
		return (2);
	}
	
	double start = getTimeInUsec();
	Vector	sortedVector = mergeInsertSortWithVector(inputVector);
	double end = getTimeInUsec();

	std::cout << "After: ";
	printContainer(std::cout, sortedVector);
	std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::vector : " << (end - start) << " usec" << std::endl;

	start = getTimeInUsec();
	List	sortedList = mergeInsertSortWithList(inputList);
	end = getTimeInUsec();
	std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::list : " << (end - start) << " usec" << std::endl;

	return (0);
}

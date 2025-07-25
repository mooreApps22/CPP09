#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>
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

Vector	loadVector(int argc, char **argv)
{
	Vector			result;
	int				intValue;	

	for (int i = 1; i < argc; i++)
	{
		std::istringstream	stream(argv[i]);

		stream >> intValue;
		if (stream.fail() || !stream.eof())
		{
			std:: cerr << "Error: Invalid input: " << argv[i] << std::endl;	
			throw std::runtime_error("stream conversion failed while loading values");
		}
		if (intValue < 0)
		{
			std:: cerr << "Error: inputs must be positive values: " << argv[i] << std::endl;
			throw std::runtime_error("stream conversion failed while loading values");
		}
		result.push_back(intValue);
	}
	return result;
}

int	main(int argc, char** argv)
{
	if (!validateArgCount(argc))
		return (1);
	Vector	inputVector;

	try
	{
		inputVector = loadVector(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception Caught: " << e.what() << std::endl;
		return (2);
	}

	Vector sortedVector = mergeInsertSortWithVector(inputVector);

	return (0);
}

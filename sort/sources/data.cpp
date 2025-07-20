#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include "data.hpp" 
#include <sys/time.h>
#include <iomanip>

double	getTimeMicroseconds()
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return t.tv_sec * 1e6 + t.tv_usec;
}

void	printTime(const std::string& name, double usec, size_t size)
{
	// 3000 log (3000) − 0.915(3000) = 7686.36376416
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << size << " elements with " << name << " : " << (usec) << " us" << std::endl;
}


std::ostream&	operator<<(std::ostream& cout, List numbers)
{

	for (ListIt it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return cout;
}

std::ostream&	operator<<(std::ostream& cout, Deque numbers)
{
	for (DequeIt it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return cout;
}

Deque	fillDeque(char **argv)
{
	Deque	numbers;	
	int		integer;

	for (int i = 1; argv[i]; i++)
	{
		std::istringstream	stream(argv[i]);

		stream >> integer;	
		if (stream.fail() || !stream.eof())
		{
			std::cerr << "Error: Invalid input: " << argv[i] << std::endl;
			continue ;
		}
		numbers.push_back(integer);		
	}
	return (numbers);
}

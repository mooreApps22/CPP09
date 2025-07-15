#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include "data.hpp" 

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

List	fillList(char **argv)
{
	List	numbers;	
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

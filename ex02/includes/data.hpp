#pragma once

#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <sstream>


typedef std::pair<int, int>					Pair;

typedef std::vector<size_t>					VectorSizeT;
typedef std::vector<int>					Vector;
typedef std::vector<bool>					VectorBool;
typedef std::vector<int>::iterator			VectorIt;
typedef std::vector<Pair>					PairVector;

typedef std::list<int>						List;
typedef std::list<int>::iterator			ListIt;
typedef std::list<Pair>						ListPair;


bool	compareSecondValues(const Pair& left, const Pair& right);
Vector	mergeInsertSortWithVector(Vector& inputVector);
List	mergeInsertSortWithList(List& inputList);


template <typename Container>
Container	loadContainer(int argc, char **argv)
{
	Container			result;
	int					intValue;	

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

template <typename Container>
std::ostream&	printContainer(std::ostream& os, const Container& c)
{
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
		os << *it << " ";
	os << std::endl;
	return os;
}

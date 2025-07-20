#include "MergeInsertionSorter.hpp"
#include <iomanip>
#include "data.hpp"

Deque	MergeInsertionSorter::getDeque() const
{
	return (_aElements);
}

void	MergeInsertionSorter::loadInput(const Deque& input)
{
	_aElements = input;
	_bElements.clear();
}

void	MergeInsertionSorter::MSsort()
{
	if (_aElements.size() <= 1)
		return ;
	_pairwiseComparison();
	_recursivelySortLarger();
	_binaryInsertSmaller();
}

void	MergeInsertionSorter::sort()
{
	MSsort();
}

void	MergeInsertionSorter::_pairwiseComparison()
{
	Deque	newA;
	List	newB;
	DequeIt	it = _aElements.begin();

	while (it != _aElements.end())
	{
		int	first = *it;
		++it;

		if (it != _aElements.end())
		{
			int second = *it;

			if(first > second)
			{
				newA.push_back(first);
				newB.push_back(second);
			}
			else
			{
				newA.push_back(second);
				newB.push_back(first);
			}
			++it;
		}
		else
		{
			// Odd element
			newB.push_back(first);
		}
	}
	_aElements = newA;
	_bElements = newB;
}

void	MergeInsertionSorter::_recursivelySortLarger()
{
	if (_aElements.size() <= 1)
		return ;

	MergeInsertionSorter	recursiveSorter;

	recursiveSorter.loadInput(_aElements);
	recursiveSorter.MSsort();
	_aElements = recursiveSorter._aElements;
}

void	MergeInsertionSorter::_binaryInsert(int value)
{
	DequeIt	low = _aElements.begin();	
	DequeIt	high = _aElements.end();	

	while (low < high)
	{
		DequeIt	mid = low + (high - low) / 2;

		if (*mid < value)
			low = mid + 1;
		else
			high = mid;
	}
	_aElements.insert(low, value);
}

void	MergeInsertionSorter::_binaryInsertSmaller()
{
	ListIt	it = _bElements.begin();

	for (; it != _bElements.end(); ++it)
		_binaryInsert(*it);
	_bElements.clear();
}

MergeInsertionSorter::MergeInsertionSorter() {}


MergeInsertionSorter::MergeInsertionSorter(const MergeInsertionSorter& other)
{
	*this = other;
}

MergeInsertionSorter& MergeInsertionSorter::operator=(const MergeInsertionSorter& other)
{
	if (this != &other)
	{
		this->_aElements = other._aElements;
		this->_bElements = other._bElements;
	}
	return (*this);
}

MergeInsertionSorter::~MergeInsertionSorter() {}

const char*	MergeInsertionSorter::SomeException::what() const throw()
{
	return ("This is some Exception!");
}

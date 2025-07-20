#pragma once
# include <iostream>
# include "data.hpp"

class MergeInsertionSorter
{
    public:
		void	MSsort();
		Deque	getDeque() const;
		void	loadInput(const Deque& input);
		void	sort();
        MergeInsertionSorter();
        MergeInsertionSorter(const MergeInsertionSorter& other);
        MergeInsertionSorter& operator=(const MergeInsertionSorter& other);
        ~MergeInsertionSorter();

		class SomeException : public std::exception
		{
			public:
				const char *what() const throw();
		};
    private:
		Deque	_aElements;
		List	_bElements;
		void	_pairwiseComparison();
		void	_recursivelySortLarger();
		void	_binaryInsertSmaller();
		void	_binaryInsert(int value);
};

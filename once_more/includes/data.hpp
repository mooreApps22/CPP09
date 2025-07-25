#pragma once

#include <vector>
#include <list>
#include <iterator>


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

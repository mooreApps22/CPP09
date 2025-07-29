#include "data.hpp"
#include <iostream>

List	mergeInsertSortWithList(List& inputList)
{	
	ListPair	pairWises;
	bool		hasOddSize = false;
	int			oddMan = 0;

	ListIt it = inputList.begin();
	while (it != inputList.end())
	{
		int	a = *it;

		++it;
		if (it == inputList.end())
		{
			hasOddSize = true;
			oddMan = a;
			break;
		}

		int b = *it;
		++it;
		if (a > b)
			std::swap(a, b);
		pairWises.push_back(std::make_pair(a, b));
	}

	pairWises.sort(compareSecondValues);
	
	List	mainChain;
	List	pend;

	for(ListPair::iterator itPair =  pairWises.begin(); itPair != pairWises.end(); ++itPair)
		mainChain.push_back(itPair->second);
	for(ListPair::iterator itPair =  pairWises.begin(); itPair != pairWises.end(); ++itPair)
		pend.push_back(itPair->first);
	
	VectorSizeT	jacobsthals;
	size_t	j0 = 0;
	size_t	j1 = 1;

	while (true)
	{
		size_t	jN = j1 + 2 * j0;

		if (jN >= pend.size())
			break ;
		jacobsthals.push_back(jN);
		j0 = j1;
		j1 = jN;
	}

	VectorBool	inserted(pend.size(), false);
	Vector		pendVec(pend.begin(), pend.end());

	for (size_t i = 0; i < jacobsthals.size(); ++i)
	{
		size_t j = jacobsthals[i];
		ListIt itJ = std::lower_bound(mainChain.begin(), mainChain.end(), pendVec[j]);
		mainChain.insert(itJ, pendVec[j]);
		inserted[j] = true;
	}
	for (size_t i = 0; i < pendVec.size(); ++i)
	{
		if (!inserted[i])
		{
			ListIt itJ = std::lower_bound(mainChain.begin(), mainChain.end(), pendVec[i]);
			mainChain.insert(itJ, pendVec[i]);
		}
	}
	if (hasOddSize)
	{
		ListIt itOdd = std::lower_bound(mainChain.begin(), mainChain.end(), oddMan);

		mainChain.insert(itOdd, oddMan);
	}
	return mainChain;
}

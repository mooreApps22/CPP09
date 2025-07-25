#include "data.hpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>



bool	compareSecondValues(const Pair& left, const Pair& right)
{
	return (left.second < right.second);
}

Vector	mergeInsertSortWithVector(Vector& inputVector)
{
	PairVector	 	pairWises;
	bool			hasOddSize = false;
	int				oddMan = 0;
 
	for (size_t i = 0; i + 1 < inputVector.size(); i += 2)
	{
		int	a = inputVector[i];	
		int	b = inputVector[i + 1];	
		if (a > b)
			std::swap(a, b);
		pairWises.push_back(std::make_pair(a, b));
	}
	if (inputVector.size() % 2 != 0)
	{
		hasOddSize = true;
		oddMan = inputVector.back();
	}
	
	std::sort(pairWises.begin(), pairWises.end(), compareSecondValues);
	
	Vector	mainChain;	

	std::cout << "Mainchain: \t";
	for (size_t i = 0; i < pairWises.size(); ++i)
	{
		mainChain.push_back(pairWises[i].second);
		std::cout << mainChain[i] << " ";
	}
	std::cout << std::endl;
	
	Vector	pend;

	std::cout << "Pend: \t\t" ;
	for (size_t i = 0; i < pairWises.size(); ++i)
	{
		pend.push_back(pairWises[i].first);
		std::cout << pend[i] << " ";
	}
	std::cout << std::endl;
	if (hasOddSize)
		std::cout << "Oddman: \t" << oddMan<< std::endl;
	
/*	
	for (size_t i = 0; i < pend.size(); ++i)
	{
		VectorIt	it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
		mainChain.insert(it, pend[i]);
	}
*/

	VectorSizeT	jacobsthals;
	size_t		j0 = 0;
	size_t		j1 = 1;

//	if (pend.size() > 0)
//		jacobsthals.push_back(j1);
		
	std::cout << "jN: \t\t";
	while (true)
	{
		size_t	jN = j1 + 2 * j0;

		if (jN >= pend.size()) 
			break;
		std::cout << jN << " ";
		jacobsthals.push_back(jN);
		j0 = j1;
		j1 = jN;
	}
	std::cout << std::endl;

	VectorBool	inserted(pend.size(), false);

	for (size_t i = 0; i < jacobsthals.size(); ++i)
	{
		size_t		j = jacobsthals[i];
		VectorIt	it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);

		mainChain.insert(it, pend[j]);
		inserted[j] = true;
	}
	
	for (size_t i = 0; i < pend.size(); ++i)
	{
		if (!inserted[i])
		{
			VectorIt	it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);

			mainChain.insert(it, pend[i]);
		}
	}

	if (hasOddSize)
	{
		VectorIt	it = std::lower_bound(mainChain.begin(), mainChain.end(), oddMan);
		mainChain.insert(it, oddMan);
	}
	
	std::cout << "MainChain: \t\t" ;
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		std::cout << mainChain[i] << " ";
	}
	std::cout << std::endl;
	return (mainChain);
}

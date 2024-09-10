/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:43:51 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/10 21:53:28 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe(std::vector<int> input) : myVec(input), myDeq(input.begin(), input.end())
{
	// std::cout << "Before :" << std::endl; //esto mejor en main y dejar constructor vacío
	// for (size_t i = 0; i < input.size(); i++)
	// 	std::cout << input[i] << " ";
	// std::cout << std::endl;

	return ;
}

PMergeMe::PMergeMe(const PMergeMe &copy) : myVec(copy.myVec), myDeq(copy.myVec.begin(), copy.myVec.end())
{
	return ;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other)
{
	if (this != & other)
	{
		this->myVec = other.myVec;
		this->myDeq = other.myDeq; //dudoso
	}
	return *this;
}

PMergeMe::~PMergeMe() { return; } ;

std::vector<int> &PMergeMe::getVec()
{
	return myVec;
}

std::vector<int> createLargerVec(std::vector<std::pair< int, int> > &pairsVec, std::vector<int> &myVec)
{
	std::vector<int> auxVec;
	
	for (size_t i = 0; i < pairsVec.size(); i++)
	{
		if (pairsVec[i].first > pairsVec[i].second)
			auxVec.push_back(pairsVec[i].first);
		else
			auxVec.push_back(pairsVec[i].second);
	}
	
	if (myVec.size() % 2 != 0)
		auxVec.push_back(myVec[myVec.size() - 1]);

	return auxVec;
}

std::vector<int> createSmallerVec(std::vector<std::pair< int, int> > &pairsVec)
{
	std::vector<int> auxVec;
	
	for (size_t i = 0; i < pairsVec.size(); i++)
	{
		if (pairsVec[i].first > pairsVec[i].second)
			auxVec.push_back(pairsVec[i].second);
		else
			auxVec.push_back(pairsVec[i].first);
	}

	return auxVec;
}

std::vector<std::pair< int, int> > createPairsVec(std::vector<int> &myVec)
{
	std::vector<std::pair< int, int> > auxVec;
	size_t pairsCount = myVec.size() / 2;
	size_t i = 0, j= 0;
	
	while (i < myVec.size() && j < pairsCount)
	{
		auxVec.push_back(std::make_pair(myVec[i], myVec[i+1]));
		i += 2;
		j++;
	}
	
	return (auxVec);
}

void PMergeMe::vecAlgorithm()
{
	std::vector<std::pair< int, int> > pairsVec = createPairsVec(myVec);
	
	std::vector<int> largerVec = createLargerVec(pairsVec, myVec);
	std::vector<int> smallerVec = createSmallerVec(pairsVec);

	std::sort(largerVec.begin(), largerVec.end());
	
	for (size_t i = 0; i < smallerVec.size(); i++)
	{
		std::vector<int>::iterator smallerPos = std::lower_bound(largerVec.begin(), largerVec.end(), smallerVec[i]);
		largerVec.insert(smallerPos, smallerVec[i]);
	}

	std::swap(myVec, largerVec);
}

//TODO
//1. quitar swap, no me gusta, cambiarlo por un return o algo así
//2. checkear necesidad if l.86
//3. print sorted
//4. hacer todo para deque
//5. buen main y error handling (before print, timestamps)
//6. operator= bien??
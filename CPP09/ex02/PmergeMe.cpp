/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:43:51 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/11 00:10:09 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe(std::vector<int> input) : myVec(input), myDeq(input.begin(), input.end())
{
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


//VECTOR
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
		auxVec.push_back(std::make_pair(myVec[i], myVec[i + 1]));
		i += 2;
		j++;
	}
	
	return (auxVec);
}

std::vector<int> PMergeMe::vecAlgorithm()
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

	return largerVec;
}

//DEQUE
std::deque<int> &PMergeMe::getDeq()
{
	return myDeq;
}

std::deque<int> createLargerDeq(std::deque<std::pair< int, int> > &pairsDeq, std::deque<int> &myDeq)
{
	std::deque<int> auxDeq;
	
	for (size_t i = 0; i < pairsDeq.size(); i++)
	{
		if (pairsDeq[i].first > pairsDeq[i].second)
			auxDeq.push_back(pairsDeq[i].first);
		else
			auxDeq.push_back(pairsDeq[i].second);
	}
	
	if (myDeq.size() % 2 != 0)
		auxDeq.push_back(myDeq[myDeq.size() - 1]);

	return auxDeq;
}

std::deque<int> createSmallerDeq(std::deque<std::pair< int, int> > &pairsDeq)
{
	std::deque<int> auxDeq;
	
	for (size_t i = 0; i < pairsDeq.size(); i++)
	{
		if (pairsDeq[i].first > pairsDeq[i].second)
			auxDeq.push_back(pairsDeq[i].second);
		else
			auxDeq.push_back(pairsDeq[i].first);
	}

	return auxDeq;
}

std::deque<std::pair< int, int> > createPairsDeq(std::deque<int> &myDeq)
{
	std::deque<std::pair< int, int> > auxDeq;
	size_t pairsCount = myDeq.size() / 2;
	size_t i = 0, j= 0;
	
	while (i < myDeq.size() && j < pairsCount)
	{
		auxDeq.push_back(std::make_pair(myDeq[i], myDeq[i + 1]));
		i += 2;
		j++;
	}
	
	return (auxDeq);
}

void PMergeMe::deqAlgorithm()
{
	std::deque<std::pair< int, int> > pairsDeq = createPairsDeq(myDeq);
	
	std::deque<int> largerDeq = createLargerDeq(pairsDeq, myDeq);
	std::deque<int> smallerDeq = createSmallerDeq(pairsDeq);

	std::sort(largerDeq.begin(), largerDeq.end());
	
	for (size_t i = 0; i < smallerDeq.size(); i++)
	{
		std::deque<int>::iterator smallerPos = std::lower_bound(largerDeq.begin(), largerDeq.end(), smallerDeq[i]);
		largerDeq.insert(smallerPos, smallerDeq[i]);
	}

	std::swap(myDeq, largerDeq);
	// printDeq(myDeq);
}

void PMergeMe::printDeq(std::deque<int> deq)
{
	std::cout << "After: ";
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i] << " ";
	std::cout << std::endl;
}

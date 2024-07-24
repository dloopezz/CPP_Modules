/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:08:11 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/24 12:30:04 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max(0)
{
	return ;
}

Span::Span(unsigned int N) : max(N)
{
	return ;
}

Span::Span(const Span &copy)
{
	this->max = copy.max;
	this->vect = copy.vect;
}

Span::~Span()
{
	return ;
}

Span &Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		this->max = assign.max;
		this->vect = assign.vect;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (vect.size() >= max)
		throw Span::ContainerFullException();
	vect.push_back(n);
}

void Span::addLotOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin < end)
	{
		addNumber(*begin);
		begin++;
	}
}

int Span::shortestSpan()
{
	if (vect.size() <= 1)
		throw Span::NotEnoughNumbersException();
	
	std::vector<int> auxVect = vect;
	std::sort(auxVect.begin(), auxVect.end());

	int shortestSpan = INT_MAX;
	for (std::vector<int>::iterator it = auxVect.begin(); it < auxVect.end() - 1; it++)
	{
		int span = *(it + 1) - *it;
		
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
}

int Span::longestSpan()
{
	if (vect.size() <= 1)
		throw Span::NotEnoughNumbersException();
	
	std::vector<int> auxVect = vect;
	std::sort(auxVect.begin(), auxVect.end());
	
	return (auxVect[auxVect.size() - 1] - auxVect[0]);
}

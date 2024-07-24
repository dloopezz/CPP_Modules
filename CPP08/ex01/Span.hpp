/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:04:20 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/24 12:28:49 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
	private:
		std::vector<int> vect;
		unsigned int max;

		class ContainerFullException : public std::exception
		{
			const char *what() const throw()
			{
				return "Container is full";
			}
		};
		class NotEnoughNumbersException : public std::exception
		{
			const char *what() const throw()
			{
				return "Not enough numbers in container to find a span";
			}
		};

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();

		Span &operator=(const Span &assign);
		
		void addNumber(int n);
		void addLotOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif
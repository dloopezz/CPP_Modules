/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:13:07 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/24 12:37:01 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;	

	try
	{
		Span sp = Span(10001);

		std::vector<int> vec;
		for (int i = 0; i < 10001; i += 5)
			vec.push_back(i);
		sp.addLotOfNumbers(vec.begin(), vec.end());
		std::cout << "Longest : " << sp.longestSpan() << std::endl;
		std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Span sp = Span(4);

		sp.addNumber(1);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	try
	{
		Span sp = Span(3);

		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(2);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	return 0;
}

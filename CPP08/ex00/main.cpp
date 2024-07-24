/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:02:41 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/24 10:11:57 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec1;
	
	vec1.push_back(2);
	vec1.push_back(1);
	vec1.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(vec1, 3);
		std::cout << "Value: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try 
	{
		std::vector<int>::iterator it = easyfind(vec1, 0);
		std::cout << "Value: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:52:15 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/14 18:05:51 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of strPTR: " << strPTR << std::endl;
	std::cout << "Memory address of strREF: " << &strREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of of str: " << str << std::endl;
	std::cout << "Value of of strPTR: " << *strPTR << std::endl;
	std::cout << "Value of of strREF: " << strREF << std::endl;
	return 0;
}

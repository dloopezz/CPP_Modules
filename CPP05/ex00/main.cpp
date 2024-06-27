/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:56:39 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/25 12:25:38 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat juan("Juan", 133);
	std::cout << juan << std::endl;
	juan.gradeDecrement();
	std::cout << juan << std::endl;

	Bureaucrat pedro("Pedro", 2);
	std::cout << pedro << std::endl;
	pedro.gradeIncrement();
	std::cout << pedro << std::endl;
	
	try
	{
		Bureaucrat paco("paco", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat juli("juli", -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat ricardo("ricardo", 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:56:39 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 09:13:54 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat juan("Juan", 133);
	std::cout << juan << std::endl;
	
	Form formA("A", 142, 142);
	juan.signForm(formA);
	std::cout << formA << std::endl;
	
	Form formB("B", 132, 142);
	juan.signForm(formB);
	std::cout << formB << std::endl;
	
	Form formC("C", 142, 132);
	juan.signForm(formC);
	std::cout << formC << std::endl;
	juan.signForm(formC);


	try
	{
		Form tooHighForm("TooHigh", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tooLowForm("TooLow", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:56:39 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/28 12:09:56 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern internA;
	Bureaucrat juan("Juan", 2);
	
	//OK cases
	try
	{
		AForm *formA = internA.makeForm("Shrubbery Creation", "Polez");
		juan.signForm(*formA);
		juan.executeForm(*formA);
		delete formA;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm *formA = internA.makeForm("Robotomy Request", "Polez");
		juan.signForm(*formA);
		juan.executeForm(*formA);
		delete formA;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm *formA = internA.makeForm("Presidential Pardon", "Polez");
		juan.signForm(*formA);
		juan.executeForm(*formA);
		delete formA;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Errors
	try
	{
		AForm *formB = internA.makeForm("Robotomy Request", "");
		juan.signForm(*formB);
		juan.executeForm(*formB);
		delete formB;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		AForm *formC = internA.makeForm("NonExistentForm", "home");
		juan.signForm(*formC);
		juan.executeForm(*formC);
		delete formC;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

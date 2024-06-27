/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:56:39 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 16:25:33 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat pringao("Pringao", 150);
	std::cout << pringao << std::endl;
	
	Bureaucrat juan("Juan", 134);
	std::cout << juan << std::endl;
	
	Bureaucrat paco("Paco", 44);
	std::cout << paco << std::endl;
	
	Bureaucrat pedro("Pedro", 4);
	std::cout << pedro << std::endl;


	ShrubberyCreationForm formA("home");
	pringao.signForm(formA);
	pringao.executeForm(formA);
	juan.signForm(formA);
	juan.executeForm(formA);
	// pedro.executeForm(formA);
	
	
	RobotomyRequestForm formB("Viti");
	paco.signForm(formB);
	paco.executeForm(formB);

	
	PresidentialPardonForm formC("Employee");
	pedro.signForm(formC);
	pedro.executeForm(formC);
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:23 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/30 19:07:26 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

Intern &Intern::operator=(const Intern &assign)
{
	(void)assign;
	return *this;
}

Intern::~Intern()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formTypes[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	if (formTarget.empty())
		throw Intern::NoTargetException();

	for (int i = 0; i < 3; i++)
	{
		if (formTypes[i] == formName)
		{
 			std::cout << "Intern creates " << formName << " Form" << std::endl;
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(formTarget);
				case 1:
					return new RobotomyRequestForm(formTarget);
				case 2:
					return new PresidentialPardonForm(formTarget);
			}
		}
	}
	throw Intern::NotFoundException();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:53:19 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/26 11:52:23 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45, "No Target") 
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("Robotomy Request Form", 72, 45, _target)
{
	std::cout << "\e[0;33mParam Constructor called\e[0m" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade(), copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->getTarget() = assign.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();

	std::cout << std::endl;
	std::cout << "*HJKSKJLLKSALKJKASKLASKLKJLJICO*" << std::endl;
	std::cout << "*KLASKLKJLJICHJKSKJLLKSALKJKASPOKNJHA*" << std::endl;

    std::srand(time(0)); // Usa el tiempo actual como semilla para el generador de números aleatorios
    if(std::rand() % 2 == 1)
        std::cout << this->getTarget() << " has been robotomized succesfully!" << std::endl;
	else
        std::cout << "Attempt to robotomize " << this->getTarget() << " failed :(" << std::endl;
	std::cout << std::endl;
}
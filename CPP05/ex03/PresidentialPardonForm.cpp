/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:53:19 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 16:28:23 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5, "No Target") 
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("Presidential Pardon Form", 25, 5, _target)
{
	std::cout << "\e[0;33mParam Constructor called\e[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade(), copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->getTarget() = assign.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();

	std::cout << std::endl;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox :O" << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:55 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 15:41:38 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("NoName"), target("NoTarget"), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

AForm::AForm(std::string _name, int _signGrade, int _execGrade, std::string _target): name(_name), target(_target), signGrade(_signGrade), execGrade(_execGrade)
{
	std::cout << "\e[0;33mParam Constructor called\e[0m" << std::endl;
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(const AForm &copy): name(copy.name), target(copy.target), isSigned(copy.isSigned), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	return ;
}

AForm &AForm::operator=(const AForm &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->isSigned = assign.isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

std::string AForm::getName() const
{
	return this->name;
}

std::string AForm::getTarget() const
{
	return this->target;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecGrade() const
{
	return this->execGrade;
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	if (this->isSigned == true)
		throw AForm::FormSignedException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
	std::string signStatus;
	if (form.getIsSigned() == true)
		signStatus = "Signed";
	else
		signStatus = "Not Signed";
	
	stream << "Form: " << form.getName() << std::endl;
	stream << "Target: " << form.getTarget() << std::endl;
	stream << "Sign Status: " <<  signStatus << std::endl;
	stream << "Sign Grade: " << form.getSignGrade() << std::endl;
	stream << "Exec Grade: " << form.getExecGrade() << std::endl;

	return stream;
}

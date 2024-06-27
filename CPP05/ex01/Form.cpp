/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:55 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 09:07:49 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("NoName"), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

Form::Form(std::string _name, int _signGrade, int _execGrade): name(_name), signGrade(_signGrade), execGrade(_execGrade)
{
	std::cout << "\e[0;33mParam Constructor called\e[0m" << std::endl;
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(const Form &copy): name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	return ;
}

Form &Form::operator=(const Form &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->isSigned = assign.isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecGrade() const
{
	return this->execGrade;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	if (this->isSigned == true)
		throw Form::FormSignedException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	std::string signStatus;
	if (form.getIsSigned() == true)
		signStatus = "Signed";
	else
		signStatus = "Not Signed";
	
	stream << "Form: " << form.getName() << std::endl;
	stream << "Sign Status: " <<  signStatus << std::endl;
	stream << "Sign Grade: " << form.getSignGrade() << std::endl;
	stream << "Exec Grade: " << form.getExecGrade() << std::endl;
	return stream;
}

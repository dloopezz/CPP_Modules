/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:30:51 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 16:20:43 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(150)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade): name(_name), grade(_grade)
{
	std::cout << "\e[0;33mParam Constructor called\e[0m" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name), grade(copy.grade)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->grade = assign.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::gradeIncrement()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::gradeDecrement()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream& stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << std::endl;
	return stream;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed the form " << form.getName() << " succesfully!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldtn't sign the form " << form.getName() << ". Reason: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed the form " << form.getName() << " succesfully!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldtn't execute the form " << form.getName() << ". Reason: " << e.what() << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:53:19 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 15:48:28 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "No Target") 
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("Shrubbery Creation Form", 145, 137, _target)
{
	std::cout << "\e[0;33mParam Constructor called\e[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade(), copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;33mDestructor called\e[0m" << std::endl;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->getTarget() = assign.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outfile(filename);
	if (!outfile.is_open())
		throw ShrubberyCreationForm::CantOpenFileException();
	else
	{
		outfile << "CPP_Modules/" << std::endl;
		outfile << "├─ CPP00/" << std::endl;
		outfile << "├─ CPP01/" << std::endl;
		outfile << "├─ CPP02/" << std::endl;
		outfile << "├─ CPP03/" << std::endl;
		outfile << "├─ CPP04/" << std::endl;
		outfile << "├─ CPP05/" << std::endl;
		outfile << "│  ├─ ex00/" << std::endl;
		outfile << "│  ├─ ex01/" << std::endl;
		outfile << "│  ├─ ex02/" << std::endl;
		outfile << "│  │  ├─ AForm.cpp" << std::endl;
		outfile << "│  │  ├─ AForm.hpp" << std::endl;
		outfile << "│  │  ├─ MuchoTexto.cpp" << std::endl << std::endl;
		
		outfile.close();
	}
}
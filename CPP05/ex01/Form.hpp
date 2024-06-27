/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:48 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 09:02:54 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include "iostream"
#include "string"
#include "exception"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
		
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw()
			{
				return "Grade is Too High";
			}	
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw()
			{
				return "Grade is Too Low";
			}
		};
		class FormSignedException : public std::exception
		{
			const char *what() const throw()
			{
				return "Form Already Signed";
			}
		};

	public:
		Form();
		Form(std::string _name, int _signGrade, int _execGrade);
		Form(const Form &copy);

		Form &operator=(const Form &assign);

		~Form();
		
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &signer);
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif

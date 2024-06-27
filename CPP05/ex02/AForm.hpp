/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:48 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 14:53:44 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include "iostream"
#include "string"
#include "exception"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const std::string	target;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
		
		class FormSignedException : public std::exception
		{
			const char *what() const throw()
			{
				return "Form Already Signed";
			}
		};

	public:
		AForm();
		AForm(std::string _name, int _signGrade, int _execGrade, std::string _target);
		AForm(const AForm &copy);

		AForm &operator=(const AForm &assign);

		virtual ~AForm();
		
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
		class FormNotSignedException : public std::exception
		{
			const char *what() const throw()
			{
				return "Form is Not Signed";
			}
		};
		
		std::string getName() const;
		std::string getTarget() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &signer);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);

#endif

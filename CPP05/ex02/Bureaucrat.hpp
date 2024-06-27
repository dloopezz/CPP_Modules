/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:21:58 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 15:43:26 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "iostream"
#include "string"
#include "exception"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw()
			{
				return "Grade is too high";
			}
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw()
			{
				return "Grade is too low";
			}
		};

	public:
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &copy);
		
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &assign);

		std::string getName() const;
		int getGrade() const;
		void gradeIncrement();
		void gradeDecrement();

		void signForm(AForm &form) const;
		void executeForm(AForm const & form);
};


std::ostream &operator<<(std::ostream& stream, const Bureaucrat &bureaucrat);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:15:05 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/28 11:45:02 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
	private:
		class NoTargetException : public std::exception
		{
			const char *what() const throw()
			{
				return "Target Not Especified";
			}
		};
		class NotFoundException : public std::exception
		{
			const char *what() const throw()
			{
				return "Form Not Found";
			}
		};
		
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &assign);
		~Intern();

		AForm *makeForm(std::string formName, std::string formTarget);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:45:24 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 15:01:11 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
	private:
		class CantOpenFileException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Error opening file");
			}
		};
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);
		
		~ShrubberyCreationForm();
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
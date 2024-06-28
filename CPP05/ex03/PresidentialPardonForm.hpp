/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:45:24 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 10:24:22 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
#define PRESIDENTIALPARDON_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		
		PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
		
		~PresidentialPardonForm();
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
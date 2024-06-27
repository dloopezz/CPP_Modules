/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:45:24 by lopezz            #+#    #+#             */
/*   Updated: 2024/06/27 16:09:09 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
		
		~RobotomyRequestForm();
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
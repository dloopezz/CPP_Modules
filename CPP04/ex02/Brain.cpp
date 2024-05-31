/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:32:26 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/30 16:55:23 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\e[0;33mBrain: Default Constructor called\e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Idea";
	return ;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "\e[0;33mBrain: Copy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

Brain &Brain::operator=(const Brain &assign)
{
	std::cout << "Brain: Assignation operator called" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = assign.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "\e[0;33mBrain: Destructor called\e[0m" << std::endl;	
}

std::string Brain::getIdea(int index)
{
	if (index < 0 || index > 99)
		return ("Error. Only 100 ideas.");
	return (this->ideas[index]);
}

void Brain::setIdea(std::string newIdea, int index)
{
	if (index < 0 || index > 99)
	{
		std::cout << "Error. Only 100 ideas." << std::endl;
		return ;
	}
	this->ideas[index] = newIdea;
	return ;
}
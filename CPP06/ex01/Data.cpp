/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:11:44 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/23 15:38:39 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : var("Hello")
{
	return;
}

Data::Data(const Data &copy) //: copy.var(this->var)
{
	*this = copy;
}

Data::~Data()
{
	return;
}

Data &Data::operator=(const Data &assign)
{
	if (this != &assign)
		var = assign.var;
	return *this;
}

void Data::setVar(std::string _var)
{
	this->var = _var;
}

std::string Data::getVar()
{
	return this->var;
}
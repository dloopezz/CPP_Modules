/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:05:18 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/23 15:11:36 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		std::string var;
	public:
		Data();
		Data(const Data &copy);
		~Data();
		Data &operator=(const Data &assign);

		void setVar(std::string _var);
		std::string getVar();
};

#endif
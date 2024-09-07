/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:42:13 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/07 12:54:03 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>

class RPN
{
	private:
		RPN();
		RPN(const RPN &copy);
		~RPN();

		class inputErrorException : public std::exception {
			const char *what() const throw() {
				return "Error: Invalid input";
			}
		};
		
	public:
		RPN &operator=(const RPN &other);
		static void exec(char *ecuation);
};

#endif
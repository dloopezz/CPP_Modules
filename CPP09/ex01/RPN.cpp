/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:42:20 by lopezz            #+#    #+#             */
/*   Updated: 2024/10/05 13:02:06 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	return ;
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
	return ;
}

RPN::~RPN()
{
	return ;
}

RPN &RPN::operator=(const RPN &other)
{
	(void) other;
	return *this;
}

std::stack<int> calc(std::stack<int> myStack, char sign)
{
	int num1, num2;
	
	num2 = myStack.top();
	myStack.pop();	
	num1 = myStack.top();
	myStack.pop();	

	switch (sign)
	{
		case '+':
			myStack.push(num1 + num2);
			break;
		case '-':
			myStack.push(num1 - num2);
			break;
		case '*':
			myStack.push(num1 * num2);
			break;
		case '/':
		    if (num2 == 0)
                throw std::runtime_error("Error: Division by zero");
			myStack.push(num1 / num2);
			break;
	}
	return myStack;
}

void RPN::exec(char *ecuation)
{		
    std::stack<int> myStack;
    char *tok = strtok(ecuation, " ");
    
    if (std::string(ecuation).empty())
        throw RPN::inputErrorException();

    while (tok)
    {
        char *endPtr;
        long num = strtol(tok, &endPtr, 10);
        
        if (*endPtr == '\0')
            myStack.push(num);
        else if (strlen(tok) == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/'))
        {
            if (myStack.size() < 2)
                throw RPN::inputErrorException();
            else
                myStack = calc(myStack, tok[0]);
        }
        else
            throw RPN::inputErrorException();
        tok = strtok(nullptr, " ");
    }
    
    if (myStack.size() == 1)
        std::cout << myStack.top() << std::endl;
    else
		throw RPN::inputErrorException();
}

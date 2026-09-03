/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:21:06 by equintas          #+#    #+#             */
/*   Updated: 2026/08/28 15:21:18 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN& RPN::operator=(const RPN& rhs)
{
    if (this != &rhs)
        this->_stack = rhs._stack;
    return (*this);
}

RPN::~RPN()
{

}

bool RPN::check_signal(const std::string& token)
{
    if (token.size() == 1 && token[0] == '+')
        return (true);
    else if (token.size() == 1 && token[0] == '-')
        return (true);
    else if (token.size() == 1 && token[0] == '*')
        return (true);
    else if (token.size() == 1 && token[0] == '/')
        return (true);
    else
        return (false);
}

void RPN::calculate(const std::string& expression)
{
    std::string token;
    std::istringstream iss(expression);

    while (iss >> token)
    {
        if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
        {
            int numb = token[0] - '0';
            this->_stack.push(numb);
        }
        else if (check_signal(token))
        {
            if (this->_stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            int numb
        }
        
    }
}
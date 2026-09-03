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
                std::cerr << "Error" << std::endl;
                return ;
            }
            int num1 = this->_stack.top();
            this->_stack.pop();
            int num2 = this->_stack.top();
            this->_stack.pop();
            if (token[0] == '+')
                this->_stack.push(num1 + num2);
            else if (token[0] == '-')
                this->_stack.push(num2 - num1);
            else if (token[0] == '*')
                this->_stack.push(num1 * num2);
            else if (token[0] == '/')
            {
                if (num1 == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return ;
                }
                this->_stack.push(num2 / num1);
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
    if (this->_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << this->_stack.top() << std::endl;
}
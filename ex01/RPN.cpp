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

void RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
}
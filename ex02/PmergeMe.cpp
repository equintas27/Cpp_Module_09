/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:23:28 by equintas          #+#    #+#             */
/*   Updated: 2026/08/28 15:23:30 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe& src)
{
    *this = src;

}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        this->_vector = rhs._vector;
        this->_deque = rhs._deque;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{

}

bool PmergeMe::IsNumber(const std::string& str, int& numb)
{
    std::istringstream iss(str);
    char extra;
    if (!(iss >> numb))
        return (false);
    if (iss >> extra)
        return (false);
    return (true);
}


void PmergeMe::ParseInput(int ac, char *av[])
{
    int numb;
    int i = 1;
    while(i < ac)
    {
        std::string str = av[i];
        if (!IsNumber(str, numb))
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
        if (numb < 0)
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
        this->_vector.push_back(numb);
        this->_deque.push_back(numb);
        i++;
    }

    std::vector<int>::iterator it = this->_vector.begin();
    while (it != this->_vector.end())
    {
        std::cout << "Vector: " << *it << std::endl;
        it++;
    }
     std::deque<int>::iterator ite = this->_deque.begin();
    while (ite != this->_deque.end())
    {
        std::cout << "Deque: " << *ite << std::endl;
        ite++;
    }
}
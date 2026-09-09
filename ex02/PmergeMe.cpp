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
{}

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
{}

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

std::vector< std::pair<int, int> > PmergeMe::makePairs(const std::vector<int>& values)
{
    std::vector< std::pair<int, int> > pairs;
    size_t i = 0;
    while (i + 1 < values.size())
    {
        int first = values[i];
        int second = values[i + 1];

        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
    std::vector<std::pair<int, int> >::iterator it;

    it = pairs.begin();
    while (it != pairs.end())
    {
        std::cout << it->first << "  " << it->second << std::endl;
        it++;
    }
}

void PmergeMe::separatePairs()
{
    std::vector<std::pair<int, int> >::iterator it;
    it = this->_pairs.begin();
    while (it != this->_pairs.end())
    {
        this->_larger.push_back(it->second);
        this->_smaller.push_back(it->first);
        it++;
    }
    std::cout << "=== Maiores ===" << std::endl;
    std::vector<int>::iterator i = this->_larger.begin();
    while (i != this->_larger.end())
    {
        std::cout << *i << std::endl;
        i++;
    }
    std::cout << "=== Menores === " << std::endl;
    std::vector<int>::iterator ite = this->_smaller.begin();
    while (ite != this->_smaller.end())
    {
        std::cout << *ite << std::endl;
        ite++;
    }
}

std::vector<int> PmergeMe::sortLarger(const std::vector<int>& values)
{

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
    std::cout << "====== Pares ======" << std::endl;
    makePairs();
    separatePairs();
}
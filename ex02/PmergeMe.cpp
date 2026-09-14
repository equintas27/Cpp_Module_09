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

t_PairingResult PmergeMe::makePairs(const std::vector<int>& values)
{
    t_PairingResult result;
    size_t i = 0;
    result.hasStraggled = false;
    if (values.size() % 2 != 0)
    {
        result.hasStraggled = true;
        result.straggled = values[values.size() - 1];
    }
    while (i + 1 < values.size())
    {
        int first = values[i];
        int second = values[i + 1];

        if (first > second)
            std::swap(first, second);
        result.pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
    return (result);
}

int findInsertPosition(const std::vector<int>& mainChain, int value)
{
    int low = 0;
    int high = mainChain.size();

    while (low < high)
    {
        int middle = low + (high - low) / 2;
        if (value > mainChain[middle])
            low = middle + 1;
        else
            high = middle;
    }
    return (low);
}

void PmergeMe::insertPendElements(std::vector<int>& mainChain, const std::vector<int>& smallers, int straggled)
{
    (void)straggled;

    size_t i = 0;
    int position; 
    while (i < smallers.size())
    {
        position = findInsertPosition(mainChain, smallers[i]);
        mainChain.insert(mainChain.begin() + position, smallers[i]);
        i++;
    }
    if (straggled != -1)
    {
        position = findInsertPosition(mainChain, straggled);
        mainChain.insert(mainChain.begin() + position, straggled);
    }
}

std::vector<int> PmergeMe::MergeInsertionSort(const std::vector<int>& numbers)
{
    std::vector<int> largers;
    std::vector<int> sortedLargers;

    if (numbers.size() <= 1)
        return (numbers);
    t_PairingResult result = makePairs(numbers);
    for (size_t it = 0; it < result.pairs.size(); it++)
        largers.push_back(result.pairs[it].second);
    sortedLargers = MergeInsertionSort(largers);
    std::vector<int> smaller;
    for (size_t i = 0; i < sortedLargers.size(); i++)
    {
        for (size_t j = 0; j < result.pairs.size(); j++)
        {
            if (sortedLargers[i] == result.pairs[j].second)
            {
                smaller.push_back(result.pairs[j].first);
                break;
            }
        }
    }
    if (result.hasStraggled)
        insertPendElements(sortedLargers, smaller, result.straggled);
    else
        insertPendElements(sortedLargers, smaller, -1);
    return (sortedLargers);
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

    std::vector<int> numbers = MergeInsertionSort(this->_vector);
    std::vector<int>::iterator a = numbers.begin();
    while (a != numbers.end())
    {
        std::cout  << *a << " ";
        a++;
    }
}
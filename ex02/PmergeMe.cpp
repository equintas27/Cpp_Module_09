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

// Vector Functions
t_PairingResultVector PmergeMe::makePairsVector(const std::vector<int>& values)
{
    t_PairingResultVector result;
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

int findInsertPositionVector(const std::vector<int>& mainChain, int value)
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

void PmergeMe::insertPendElementsVector(std::vector<int>& mainChain, const std::vector<int>& smallers, int straggled)
{
    size_t i = 0;
    int position; 
    while (i < smallers.size())
    {
        position = findInsertPositionVector(mainChain, smallers[i]);
        mainChain.insert(mainChain.begin() + position, smallers[i]);
        i++;
    }
    if (straggled != -1)
    {
        position = findInsertPositionVector(mainChain, straggled);
        mainChain.insert(mainChain.begin() + position, straggled);
    }
}

std::vector<int> PmergeMe::MergeInsertionSortVector(const std::vector<int>& numbers)
{
    std::vector<int> largers;
    std::vector<int> sortedLargers;

    if (numbers.size() <= 1)
        return (numbers);
    t_PairingResultVector result = makePairsVector(numbers);
    for (size_t it = 0; it < result.pairs.size(); it++)
        largers.push_back(result.pairs[it].second);
    sortedLargers = MergeInsertionSortVector(largers);
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
        insertPendElementsVector(sortedLargers, smaller, result.straggled);
    else
        insertPendElementsVector(sortedLargers, smaller, -1);
    return (sortedLargers);
}

// Deque Functions
t_PairingResultDeque PmergeMe::makePairsDeque(const std::deque<int>& values)
{
    t_PairingResultDeque result;
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

int findInsertPositionDeque(const std::deque<int>& mainChain, int value)
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

void PmergeMe::insertPendElementsDeque(std::deque<int>& mainChain, const std::deque<int>& smallers, int straggled)
{
    size_t i = 0;
    int position; 
    while (i < smallers.size())
    {
        position = findInsertPositionDeque(mainChain, smallers[i]);
        mainChain.insert(mainChain.begin() + position, smallers[i]);
        i++;
    }
    if (straggled != -1)
    {
        position = findInsertPositionDeque(mainChain, straggled);
        mainChain.insert(mainChain.begin() + position, straggled);
    }
}

std::deque<int> PmergeMe::MergeInsertionSortDeque(const std::deque<int>& numbers)
{
    std::deque<int> largers;
    std::deque<int> sortedLargers;

    if (numbers.size() <= 1)
        return (numbers);
    t_PairingResultDeque result = makePairsDeque(numbers);
    for (size_t it = 0; it < result.pairs.size(); it++)
        largers.push_back(result.pairs[it].second);
    sortedLargers = MergeInsertionSortDeque(largers);
    std::deque<int> smaller;
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
        insertPendElementsDeque(sortedLargers, smaller, result.straggled);
    else
        insertPendElementsDeque(sortedLargers, smaller, -1);
    return (sortedLargers);
}

void PmergeMe::printAll(const std::vector<int>& vector, const std::deque<int>& deque)
{
     std::cout << "Before: ";
    for (size_t j = 0; j < vector.size(); j++)
        std::cout << vector[j] << " ";
    std::cout << std::endl;
    std::clock_t start_v = std::clock();
    std::vector<int> numbersVector = MergeInsertionSortVector(vector);
    std::clock_t end_v = std::clock();
    double timeVector = static_cast<double>(end_v - start_v) / (CLOCKS_PER_SEC / 1000000.0);
    std::cout << "After: ";
    for (size_t k = 0; k < numbersVector.size(); k++)
        std::cout << numbersVector[k] << " ";
    std::clock_t start_d = std::clock();
    std::deque<int> numbersDeque = MergeInsertionSortDeque(deque);
    std::clock_t end_d = std::clock();
    double timeDeque = static_cast<double>(end_d - start_d) / (CLOCKS_PER_SEC / 1000000.0);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector<int>: " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque<int>: " << timeDeque << " us" << std::endl;
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
        if (numb <= 0)
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
        this->_vector.push_back(numb);
        this->_deque.push_back(numb);
        i++;
    }
    printAll(this->_vector, this->_deque);
}
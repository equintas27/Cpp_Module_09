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

/*void PmergeMe::separatePairs(const std::vector< std::pair<int, int> >& pairs, std::vector<int>& smaller, std::vector<int>& larger)
{
    std::vector<std::pair<int, int> >::const_iterator it;
    it = pairs.begin();
    while (it != pairs.end())
    {
        larger.push_back(it->second);
        smaller.push_back(it->first);
        it++;
    }
    std::cout << "=== Maiores ===" << std::endl;
    std::vector<int>::iterator i = larger.begin();
    while (i != larger.end())
    {
        std::cout << *i << std::endl;
        i++;
    }
    std::cout << "=== Menores === " << std::endl;
    std::vector<int>::iterator ite = smaller.begin();
    while (ite != smaller.end())
    {
        std::cout << *ite << std::endl;
        ite++;
    }
}

std::vector<size_t> generateJacobsthalSequence(size_t size)
{
    std::vector<size_t> jacob;
    if (size == 0)
        return jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (true)
    {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
        if (next >= size)
            break;
    }
    return jacob;
}

void PmergeMe::insertPendElements(std::vector<int>& mainChain, const std::vector<int>& pend, int unpaired)
{
    size_t pendSize = pend.size();
    if (pendSize <= 1 && unpaired == -1)
        return;

    std::vector<size_t> jacobSequence = generateJacobsthalSequence(pendSize);
    std::vector<bool> inserted(pendSize, false);
    inserted[0] = true; 
    for (size_t k = 3; k < jacobSequence.size(); ++k)
    {
        size_t targetIndex = jacobSequence[k] - 1;
        if (targetIndex >= pendSize)
            targetIndex = pendSize - 1;

        size_t boundIndex = jacobSequence[k - 1] - 1;
        for (size_t i = targetIndex; i > boundIndex; --i)
        {
            if (i < pendSize && !inserted[i])
            {
                int valToInsert = pend[i];
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
                mainChain.insert(pos, valToInsert);

                inserted[i] = true;
            }
        }
    }
    for (size_t i = 1; i < pendSize; ++i)
    {
        if (!inserted[i])
        {
            int valToInsert = pend[i];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(pos, valToInsert);
            inserted[i] = true;
        }
    }
    if (unpaired != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
}*/

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
    int position = findInsertPosition(mainChain, smallers[0]);
    mainChain.insert ();
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
    if (!smaller.empty())
        sortedLargers.insert(sortedLargers.begin(), smaller[0]);

    insertPendElements(sortedLargers, smaller, result.hasStraggled ? result.straggled : -1);
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
    /*std::cout << "====== Pares ======" << std::endl;
    t_PairingResult res = makePairs(this->_vector);
    std::vector<int> smaller;
    std::vector<int> larger;
    if (res.hasStraggled)
        std::cout << "Straggled: " << res.straggled << std::endl;
    separatePairs(res.pairs, smaller, larger);*/

    std::vector<int> numbers = MergeInsertionSort(this->_vector);
    std::vector<int>::iterator a = numbers.begin();
    while (a != numbers.end())
    {
        std::cout  << *a << " ";
        a++;
    }
}
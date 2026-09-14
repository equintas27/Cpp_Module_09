/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:24:08 by equintas          #+#    #+#             */
/*   Updated: 2026/08/28 15:24:10 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <string>
#include <deque>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <utility>

typedef struct s_PairingResult
{
    std::vector< std::pair<int, int> > pairs;
    int straggled;
    bool hasStraggled;
} t_PairingResult;


class PmergeMe
{
    private:
        std::vector<int>  _vector;
        std::deque<int> _deque;
        t_PairingResult makePairs(const std::vector<int>& values);
        void separatePairs(const std::vector< std::pair<int, int> >& pairs, std::vector<int>& smaller, std::vector<int>& larger);
        bool IsNumber(const std::string& str, int& numb);
        std::vector<int> MergeInsertionSort(const std::vector<int>& numbers);
        void insertPendElements(std::vector<int>& mainChain, const std::vector<int>& smallers, int straggled);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();
        void ParseInput(int ac, char *av[]);
};

#endif

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
#include <sys/time.h>

typedef struct s_PairingResultVector
{
    std::vector< std::pair<int, int> > pairs;
    int straggled;
    bool hasStraggled;
} t_PairingResultVector;

typedef struct s_PairingResultDeque
{
    std::deque< std::pair<int, int> > pairs;
    int straggled;
    bool hasStraggled;
} t_PairingResultDeque;


class PmergeMe
{
    private:
        std::vector<int>  _vector;
        std::deque<int> _deque;
        bool IsNumber(const std::string& str, int& numb);

        // Vector
        t_PairingResultVector makePairsVector(const std::vector<int>& values);
        std::vector<int> MergeInsertionSortVector(const std::vector<int>& numbers);
        void insertPendElementsVector(std::vector<int>& mainChain, const std::vector<int>& smallers, int straggled);

        // Deque
        t_PairingResultDeque makePairsDeque(const std::deque<int>& values);
        std::deque<int> MergeInsertionSortDeque(const std::deque<int>& numbers);
        void insertPendElementsDeque(std::deque<int>& mainChain, const std::deque<int>& smallers, int straggled);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();
        void ParseInput(int ac, char *av[]);
};

#endif

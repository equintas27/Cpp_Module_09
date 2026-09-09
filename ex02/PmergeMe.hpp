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

class PmergeMe
{
    private:
        std::vector<int>  _vector;
        std::deque<int> _deque;
        std::vector<int> _smaller;
        std::vector<int> _larger;
        std::vector< std::pair<int, int> > makePairs(const std::vector<int>& values);
        void separatePairs();
        bool IsNumber(const std::string& str, int& numb);
        std::vector<int> sortLarger(const std::vector<int>& values);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();
        void ParseInput(int ac, char *av[]);
};

#endif

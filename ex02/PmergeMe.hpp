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

class PmergeMe
{
    private:
        std::vector<int>  _vector;
        std::deque<int> _deque;
        bool IsNumber(const std::string& str, int& numb);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();
        void ParseInput(int ac, char *av[]);
};

#endif

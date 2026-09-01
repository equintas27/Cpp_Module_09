/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:19:38 by equintas          #+#    #+#             */
/*   Updated: 2026/08/28 15:19:40 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        void loadDatabase();
        bool isValidDate(const std::string& date);
        int isValidValue(double value);
        double getExchangeRate(const std::string& date);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();
        void processInput(const std::string& filename);
};

#endif

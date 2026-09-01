/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:19:30 by equintas          #+#    #+#             */
/*   Updated: 2026/08/28 15:19:32 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    double rate;

    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> rate;
        this->_database[date] = rate;
    }
    std::map<std::string, double>::iterator i = this->_database.begin();
    while (i != this->_database.end())
    {
        std::cout << i->first << " --> " << i->second << std::endl;
        i++;
    }
}


BitcoinExchange::BitcoinExchange()
{
    loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
        this->_database = rhs._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}



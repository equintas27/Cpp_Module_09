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
        std::cerr << "Error: could not open file of data" << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    double rate;

    std::getline(file, line);
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        ss >> rate;
        this->_database[date] = rate;
    }
    /*std::map<std::string, double>::iterator i = this->_database.begin();
    while (i != this->_database.end())
    {
        std::cout << i->first << " --> " << i->second << std::endl;
        i++;
    }*/
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    

    if (date.size() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);

    int year;
    int month;
    int day;

    std::string yearStr;
    std::string monthStr;
    std::string dayStr;

    std::stringstream ss(date);
    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr, '-');

    std::stringstream(yearStr) >> year;
    std::stringstream(monthStr) >> month;
    std::stringstream(dayStr) >> day;

    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

void BitcoinExchange::processInput(const std::string& filename)
{   
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file of input" << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    double value;

    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::getline(ss, date, '|');
        std::stringstream clean(date);
        clean >> date;
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        ss >> value;
        std::cout << "DATE [" << date << "]"<< std::endl;
        std::cout << "VALUE ["<< value << "]"<< std::endl;
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



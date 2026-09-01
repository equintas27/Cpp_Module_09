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
    int max_day;

    std::string yearStr;
    std::string monthStr;
    std::string dayStr;

    std::stringstream ss(date);
    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr, '-');
    if (!std::isdigit(yearStr[0]) ||
        !std::isdigit(yearStr[1]) ||
        !std::isdigit(yearStr[2]) ||
        !std::isdigit(yearStr[3]))
            return (false);
    if (!std::isdigit(monthStr[0]) ||
        !std::isdigit(monthStr[1]))
            return (false);
    if (!std::isdigit(dayStr[0]) ||
        !std::isdigit(dayStr[1]))
            return (false);

    std::stringstream(yearStr) >> year;
    std::stringstream(monthStr) >> month;
    std::stringstream(dayStr) >> day;

    if (month < 1 || month > 12)
        return (false);
    if (day < 1)
        return (false);
    if (month == 2)
    {
        max_day = 28;
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
                max_day = 29;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        max_day = 30;
    else
        max_day = 31;
    if (day > max_day)
        return (false);
    return (true);
}

int BitcoinExchange::isValidValue(double value)
{
    if (value < 0)
        return (1);
    else if (value > 1000)
        return (2);
    return (0);
}

double BitcoinExchange::getExchangeRate(const std::string& date)
{

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
        if (!(ss >> value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(isValidValue(value) == 1)
        {
            std::cerr << "Error: not a positive number" << std::endl;
            continue;
        }
        else if (isValidValue(value) == 2)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
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
{}

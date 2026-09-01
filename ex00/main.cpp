/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:18:42 by equintas          #+#    #+#             */
/*   Updated: 2026/08/28 15:18:44 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        BitcoinExchange bt;
        bt.processInput(av[1]);
    }
    else
        std::cerr << "Error: could not open file" << std::endl;
    return (0);
}

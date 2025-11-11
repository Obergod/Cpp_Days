/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:42:15 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/11 18:51:12 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BtcExchange::BtcExchange()
{
	std::cout << "BtcExchange Default constructor called" << std::endl;
}

BtcExchange::BtcExchange( const BtcExchange &other )
{
	std::cout << "BtcExchange copy constructor called" << std::endl;
}

BtcExchange	&BtcExchange::operator=( const BtcExchange &other )
{
	if (this != &other)
	{
	}
	std::cout << "BtcExchange assignement operator called" << std::endl;
	return (*this);
}

BtcExchange::~BtcExchange()
{
	std::cout << "BtcExchange Default destructor called" << std::endl;
}

void	BtcExchange::fillRate( const std::string &fileName )
{
	std::ifstream	file(fileName.c_str());
	std::string	line;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string	date;
		double nb;
		std::getline(ss, date, ','); 
		if (ss >> nb && ss.eof())
			throw BadInputException();
		_rate.push_back(std::make_pair(date, nb));
	}
}

void	BtcExchange::checkError()
{
	for (std::vector<std::pair<std::string, double>>::iterator it = _rate.begin(); 
			it != _rate.end(); it++)
	{
	}
}

bool	BtcExchange::isValidDate( std::vector<std::pair<std::string, double>>::iterator it )
{
	std::string date = std::get<0>(*it);

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
}


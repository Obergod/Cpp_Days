/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:42:15 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/12 22:13:54 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BtcExchange::BtcExchange()
{
	std::cout << "BtcExchange Default constructor called" << std::endl;
}

BtcExchange::BtcExchange( const BtcExchange &other ) : _rate(other._rate), _database(other._database)
{
	std::cout << "BtcExchange copy constructor called" << std::endl;
}

BtcExchange	&BtcExchange::operator=( const BtcExchange &other )
{
	if (this != &other)
	{
		_rate = other._rate;
		_database = other._database;
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
	if (!file.is_open())
		throw std::runtime_error("Could not open input file");

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string	date;
		double nb;
		std::getline(ss, date, '|'); 
		if (!(ss >> nb) || !ss.eof())
			throw BadInputException();
		_rate.insert(std::make_pair(date, nb));
	}
	checkError();
}

void	BtcExchange::checkError()
{
	for (std::map<std::string, double>::iterator it = _rate.begin(); 
			it != _rate.end(); it++)
	{
		if (!isValidNb(it))
			throw InvalidNbException();
		if (!isValidDate(it))
			throw InvalidDateException();
	}
}

bool	BtcExchange::isValidNb( std::map<std::string, double>::iterator it )
{
	double	nb = it->second;

	if (nb < 0 || nb > 1000)
		return false;
	return true;
}

bool	BtcExchange::isValidDate( std::map<std::string, double>::iterator it )
{
	std::string date = it->first;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::stringstream ss(date);
	char	dash1, dash2;	
	int		year, month, day;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || !ss.eof())
		return false;

	if (day < 1 || day > 31)
		return false;
	if (month < 1 || month > 12)
		return false;

	int	days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2)
	{
		bool	leap = (year % 4 == 0 && (year % 100 != 0 || year% 400 == 0));
	
		return (day <= (leap ? 28 : 29));
	}
	else
		return (day <= days_in_month[month - 1]);
}

void	BtcExchange::loadDatabase( const std::string &fileName )
{
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open database file");

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string	date;
		double nb;
		std::getline(ss, date, ','); 
		if (!(ss >> nb) || !ss.eof())
			throw BadInputException();
		_database.insert(std::make_pair(date, nb));
	}
	checkError();
}

double	BtcExchange::getCvsRate(const std::string &date)
{
	std::map<std::string, double>::iterator it = _database.lower_bound(date);

	if (it->first == date)
		return it->second;
	
	if (it == _database.begin())
		throw DateTooEarlyException();

	std::cout << "Closest date found: " << it->first;
	--it;

	return it->second;
}

void	BtcExchange::printBtcRate()
{
	for (std::map<std::string, double>::iterator it = _rate.begin(); 
			it != _rate.end(); it++)
	{
		double	btcrate = getCvsRate(it->first); 
		std::cout << it->first << " >= " << it->second << " = " << (it->second * btcrate) << std::endl;
	}
}

const char *BtcExchange::BadInputException::what() const throw()
{
	return ("Error: Bad input");
}

const char *BtcExchange::InvalidNbException::what() const throw()
{
	return ("Error: Invalid Number");
}

const char *BtcExchange::InvalidDateException::what() const throw()
{
	return ("Error: Date invalid");
}

const char *BtcExchange::DateTooEarlyException::what() const throw()
{
	return ("Error: Date pre-exists bitcoin");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:42:15 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/13 21:01:03 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BtcExchange::BtcExchange()
{
	std::cout << "BtcExchange Default constructor called" << std::endl;
}

BtcExchange::BtcExchange( const BtcExchange &other ) :  _database(other._database)
{
	std::cout << "BtcExchange copy constructor called" << std::endl;
}

BtcExchange	&BtcExchange::operator=( const BtcExchange &other )
{
	if (this != &other)
	{
		_database = other._database;
	}
	std::cout << "BtcExchange assignement operator called" << std::endl;
	return (*this);
}

BtcExchange::~BtcExchange()
{
	std::cout << "BtcExchange Default destructor called" << std::endl;
}

void	BtcExchange::printBtcRate( const std::string &fileName )
{
	if (_database.empty())
		loadDatabase("data.csv");

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

		date.erase(0, date.find_first_not_of(" \t\n\r"));
        date.erase(date.find_last_not_of(" \t\n\r") + 1);

		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid Date => " << date << std::endl;
			continue ;
		}

		if (!(ss >> nb) || !ss.eof())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		if (!isValidNb(nb))
		{
			continue ;
		}

		try 
		{
			double	btcrate = getCvsRate(date); 
			std::cout << date << " => " << nb << " = " << (nb * btcrate) << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

	}
}

bool	BtcExchange::isValidNb( double nb )
{
	if (nb < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (nb > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BtcExchange::isValidDate( const std::string &date )
{
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
	
		return (day <= (leap ? 29 : 28));
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
		std::string date;
		double nb;
		
		if (std::getline(ss, date, ',') && ss >> nb && ss.eof())
		{
			_database.insert(std::make_pair(date, nb));
		}
	}
	file.close();
}

double	BtcExchange::getCvsRate(const std::string &date)
{
	std::map<std::string, double>::iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return it->second;
	
	if (it == _database.begin())
		throw DateTooEarlyException();

	--it;

	return it->second;
}

const char *BtcExchange::DateTooEarlyException::what() const throw()
{
	return ("Error: Date pre-exists bitcoin");
}

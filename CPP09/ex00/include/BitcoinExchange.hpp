/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:11:46 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/12 21:40:42 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <map>

class	BtcExchange
{
	private:
		std::map<std::string, double> _rate;
		std::map<std::string, double> _database;
	public:
		BtcExchange();
		BtcExchange(const BtcExchange &other);
		BtcExchange &operator=(const BtcExchange &other);
		~BtcExchange();

		void	fillRate( const std::string &fileName );
		void	checkError();
		bool	isValidDate( std::map<std::string, double>::iterator it );
		bool	isValidNb( std::map<std::string, double>::iterator it );

		void	loadDatabase( const std::string &fileName );
		double	getCvsRate(const std::string &date);
		void	printBtcRate();

		class	BadInputException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class	InvalidNbException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	InvalidDateException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	DateTooEarlyException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};














#endif

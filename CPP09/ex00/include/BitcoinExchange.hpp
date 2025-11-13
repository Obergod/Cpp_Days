/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:11:46 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/13 18:09:51 by mafioron         ###   ########.fr       */
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
		std::map<std::string, double> _database;
	public:
		BtcExchange();
		BtcExchange(const BtcExchange &other);
		BtcExchange &operator=(const BtcExchange &other);
		~BtcExchange();

		void	printBtcRate( const std::string &fileName );
		bool	isValidDate( const std::string &date );
		bool	isValidNb( double nb );

		void	loadDatabase( const std::string &fileName );
		double	getCvsRate(const std::string &date);

		class	DateTooEarlyException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};














#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:11:46 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/11 17:26:31 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>

class	BtcExchange
{
	private:
		std::vector<std::pair<std::string, double>>	_rate;
	public:
		BtcExchange();
		BtcExchange(const BtcExchange &other);
		BtcExchange &operator=(const BtcExchange &other);
		~BtcExchange();

		void	fillRate( const std::string &fileName );
		void	checkError();
		bool	isValidDate(std::vector<std::pair<std::string, double>>::iterator it);

		class	BadInputException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};














#endif

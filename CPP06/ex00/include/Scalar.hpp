/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:22 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/20 22:29:19 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cmath>


class	Scalar
{
	private:
		static bool	isChar( const std::string &s );
		static bool	isInt( const std::string &s );
		static bool	isDouble( const std::string &s ); 
		static bool	isFloat( const std::string &s ); 
		static bool	isNan( const std::string &s );
		static void	outputAsChar(std::string &s);
		static void	outputAsInt(std::string &s);
		static void	outputAsDouble(std::string &s);
		static void	outputAsFloat(std::string &s);
		static void	outputAsNan();

	public:
		Scalar();
		Scalar( const Scalar &other );
		Scalar &operator=( const Scalar &other );
		~Scalar();

		static void	convert(std::string &s);
};








#endif

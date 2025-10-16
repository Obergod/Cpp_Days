/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:22 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/16 20:08:32 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>


class	Scalar
{
	private:
		static bool	isChar( const std::string &s );
		static bool	isInt( const std::string &s );
		static bool	isDouble( const std::string &s ); 
		static bool	isFloat( const std::string &s ); 

	public:
		Scalar();
		Scalar( const Scalar &other );
		Scalar &operator=( const Scalar &other );
		~Scalar();

		static void	convert(std::string &s);
};








#endif

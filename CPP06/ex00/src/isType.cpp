/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isType.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:21:37 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/20 22:44:51 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

bool	Scalar::isNan( const std::string &s )
{
	if (s.empty())
		return false;

	std::stringstream	ss(s);
	double d;
	ss >> d;


	if (ss >> d && ss.eof())
		return false;
	return true;
}

bool	Scalar::isChar( const std::string &s )
{
	if (s.empty() || s.size() > 1)
		return false;
	if (s[0] < 32 || s[0] > 126)
		return false;
	return true;
}

bool	Scalar::isInt( const std::string &s ) 
{
	if (s.empty())
		return false;

	std::stringstream	ss(s);
	int	i;

	if (ss >> i && ss.eof())
		return true;
	return false;
}

bool	Scalar::isDouble( const std::string &s ) 
{
	if (s.empty())
		return false;

	std::stringstream	ss(s);
	double d;

	if (s.find('.') == std::string::npos)
		return false;
	if (ss >> d && ss.eof())
		return true;
	return false;
}

bool	Scalar::isFloat( const std::string &s ) 
{
	if (s.empty())
		return false;


	if (s.find('.') == std::string::npos)
		return false;
	if (s[s.size() - 1]!= 'f')
		return false;

	std::string noF = s.substr(0, s.size() - 1);
	std::stringstream	ss(noF);
	float f;

	if (ss >> f && ss.eof())
		return true;
	return false;
}




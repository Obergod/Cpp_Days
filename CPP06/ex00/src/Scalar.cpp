/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:13 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/16 21:45:35 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar()
{
	std::cout << "Scalar default constructor called" << std::endl;
}

Scalar::Scalar( const Scalar &other )
{
	std::cout << "Scalar copy constructor called" << std::endl;
}	

Scalar &Scalar::operator=( const Scalar &other )
{
	std::cout << "Scalar assignement operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

Scalar::~Scalar()
{
	std::cout << "Scalar default destructor called" << std::endl;
}

static bool	isChar( const std::string &s )
{
	if (s.empty() || s.size() > 1)
		return false;
	if (s[0] < 32 || s[0] > 126)
		return false;
	return true;
}

static bool	isInt( const std::string &s ) 
{
	if (s.empty())
		return false;

	std::stringstream	ss(s);
	int	i;

	if (ss >> i && ss.eof())
		return true;
	return false;
}

static bool	isDouble( const std::string &s ) 
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

static bool	isFloat( const std::string &s ) 
{
	if (s.empty())
		return false;

	std::stringstream	ss(s);
	float f;

	if (s.find('.') == std::string::npos)
		return false;
	if (s.back() != 'f')
		return false;

	std::string noF = s.substr(0, s.back() - 2);

	if (ss >> f && ss.eof())
		return true;
	return false;
}

static void	convert( std::string &s )
{
	
}

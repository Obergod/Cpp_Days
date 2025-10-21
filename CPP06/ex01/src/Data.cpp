/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:58:53 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 19:34:05 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( const std::string desc, const std::string &name, int nbHead, int nbEyes ): _name(""), _desc(desc),
																						_nbHead(nbHead), _nbEyes(nbEyes)
{
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(): _name("Human"), _desc("Perfectly normal"), _nbHead(1), _nbEyes(2)
{
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data( const Data &other ): _name(other._name), _desc(other._desc), _nbHead(other._nbHead), _nbEyes(other._nbEyes)
{
	std::cout << "Data copy constructor called" << std::endl;
}	

Data &Data::operator=( const Data &other )
{
	std::cout << "Data assignement operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_nbHead = other._nbHead;
		_nbEyes = other._nbEyes;
		_desc = other._desc;
	}
	return *this;
}

Data::~Data()
{
	std::cout << "Data default destructor called" << std::endl;
}


std::string Data::getName()
{
	return _name;
}

std::string Data::getDesc()
{
	return _desc;
}

int Data::getNbHead()
{
	return _nbHead;
}

int Data::getNbEyes()
{
	return _nbEyes;
}

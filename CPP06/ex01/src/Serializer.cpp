/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:47:56 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 19:19:30 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer( const Serializer &other )
{
	std::cout << "Serializer copy constructor called" << std::endl;
}	

Serializer &Serializer::operator=( const Serializer &other )
{
	std::cout << "Serializer assignement operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer default destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

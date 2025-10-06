/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:13:23 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/06 16:13:24 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _memoryNb(0)
{
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &other ) : _memoryNb(other._memoryNb)
{
	for (int i = 0; i < _memoryNb; i++)
	{
		_memory[i] = other._memory[i]->clone();
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other )
{
	std::cout << "MateriaSource assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_memory[i])
			{
				delete _memory[i];
				_memory[i] = NULL;
			}
		}

		for (int i = 0; i < _memoryNb; i++)
		{
			_memory[i] = other._memory[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i])
		{
			delete _memory[i];
			_memory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;

	if (_memoryNb > 3 )
	{
		std::cout << "memory full !" << std::endl;
		return ;
	}

	_memory[_memoryNb] = m->clone();
	std::cout << m->getType() << " Materia added" << std::endl;
	_memoryNb++;
	std::cout << "You have " << (4 - _memoryNb) << " memory slot left" << std::endl;

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (_memoryNb == 0)
	{
		std::cout << "no Materia to copy" << std::endl;
		return (NULL);
	}

	for (int i = (_memoryNb - 1); i >= 0; i--)
	{
		if (_memory[i]->getType() == type)
			return _memory[i]->clone();
	}
	std::cout << "type is unknown or dosen't exist in memory" << std::endl;
	return NULL;
}

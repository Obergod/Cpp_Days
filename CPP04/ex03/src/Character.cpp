/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:45:33 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:45:34 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( std::string name ) : _name(name), _materiaNb(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character( const Character &other ) : _name(other._name), _materiaNb(other._materiaNb)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=( const Character &other )
{
	std::cout << "Character assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		
		_name = other._name;
		_materiaNb = other._materiaNb;

		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Character default destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}


void	Character::equip( AMateria *m )
{
	if (!m)
		return ;

	if (_materiaNb > 3 )
	{
		std::cout << "Inventory full !" << std::endl;
		return ;
	}

	for	(int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m->clone();
			std::cout << m->getType() << " Materia added" << std::endl;
			_materiaNb++;
			std::cout << "You have " << (4 - _materiaNb) << " inventory slot left" << std::endl;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 ||idx > 3 || _inventory[idx] == NULL)
	{
		std::cout << "Can't unequip, there is nothing here" << std::endl;
		return ;
	}
	
	_inventory[idx] = NULL;
	_materiaNb--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 ||idx > 3 || _inventory[idx] == NULL)
	{
		std::cout << "Can't use this materia, it dosen't exist" << std::endl;
		return ;
	}

	_inventory[idx]->use(target);
}

















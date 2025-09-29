/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:26:59 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/28 18:27:00 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ): _name(other._name), _hitPoints(other._hitPoints),
											_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &other )
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap Copy Assignment Operator Called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Default Destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << _name << " can't attack he is still dead :(" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << _name << " can't attack he Has no more energy points !" << std::endl;
	else
	{
		std::cout << _name << " attacks " << target << ", causing "
				<< _attackDamage << " points of damage !\n";
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage( unsigned int value )
{
	if (this->_hitPoints <= 0)
		std::cout << _name << " is already dead :(" << std::endl;
	else
	{
		this->_hitPoints -= value;
		if (this->_hitPoints <= 0)
			std::cout << _name << " is dead :(" << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int value)
{
	if (this->_hitPoints <= 0)
		std::cout << _name << " can't repair he is still dead :(" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << _name << " can't repair he has no more energy points !" << std::endl;
	else
	{
		int	heal = _hitPoints + value;
		if (heal > 10)
		{
			_hitPoints = 10;
			std::cout << _name << " repairs itself for " << (10 - (_hitPoints - value)) << " hit points!" << std::endl;
		}
		else
		{
			_hitPoints += value;
			std::cout << _name << " repairs itself for " << value << " hit points!" << std::endl;
		}
		_energyPoints-= value;
	}
}

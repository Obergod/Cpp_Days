/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:19:41 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/29 17:19:42 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHp = _hitPoints;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << _name << " Is Guarding the gate" << std::endl;
}

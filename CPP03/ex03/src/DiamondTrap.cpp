/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:48:30 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/29 20:48:30 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) :
						ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_maxHp = _hitPoints;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : 
							ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &other )
{
	if (this != &other)
	{
		FragTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap Copy Assignment Operator Called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Default Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am : " << _name << ", my clap name is : " << ClapTrap::_name << std::endl;
}

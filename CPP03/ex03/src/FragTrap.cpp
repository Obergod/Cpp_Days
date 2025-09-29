/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:21:03 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/29 19:21:04 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_maxHp = _hitPoints;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=( const FragTrap &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Default Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << _name << " < Hey hey highfive me! >\n"
			<< "Do you want to Highfive him?\n" << "Yes | No" << std::endl;
	std::string line;
	getline(std::cin, line);
	if (line == "Yes" || line == "yes" || line == "y")
	{
		std::cout << "Are you sure you want to highfive this thing ?\n"
					<< "Yes | No" << std::endl;
		getline(std::cin, line);
		if (line == "Yes" || line == "yes" || line == "y")
		{
			std::cout << "Really ?   ...\n" << "its your choise after all..." << std::endl;
			std::cout << _name << " < OH YEAH HIGHFIVE >" << std::endl;
		}
		else if (line == "No" || line == "no" || line == "N")
			std::cout << "Good decision" << std::endl;
		else
			std::cout << "No one understands your giberish " <<
				_name << " leaves" << std::endl;
	}
	else if (line == "No" || line == "no" || line == "N")
		std::cout << "Good decision" << std::endl;
	else
		std::cout << "No one understands your giberish " <<
			_name << " leaves" << std::endl;
}

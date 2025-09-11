/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:27:30 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/11 19:27:31 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::set_name(std::string name)
{
		this->name = name;
}

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie *z = new Zombie[n];
	if (z == NULL)
	{
		std::cout << "alloc failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < n; i++)
		z[i].set_name(name);
	return z;
}

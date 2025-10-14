/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:01:43 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/11 17:01:44 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*z1 = newZombie("paulette");
	if (z1 == NULL)
	{
		std::cout << "alloc failed" << std::endl;
		return (1);
	}
	randomChump("henry");
	randomChump("Hubert");
	z1->announce();
	z1->announce();
	delete z1;
	return (0);
}

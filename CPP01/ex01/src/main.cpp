/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:27:38 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/11 19:27:39 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	n = 0;

	Zombie	*z1 = zombieHorde(n, "henry");
	if (z1 == NULL)
		return (1);
	for (int i = 0; i < n; i++)
		z1->announce();
	delete[] z1;
	return (0);
}

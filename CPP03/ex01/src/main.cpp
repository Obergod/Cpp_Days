/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:26:43 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/28 18:26:44 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <sstream>

int main()
{
	std::cout << "\n=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("Warrior");
	ClapTrap clap2("Defender");
	
	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	ClapTrap clap3(clap1);
	
	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	ClapTrap clap4("TempName");
	clap4 = clap2;
	
	std::cout << "\n=== Testing Attack Function ===" << std::endl;
	clap1.attack("Enemy1");
	clap1.attack("Enemy2");
	clap1.attack("Enemy3");
	
	std::cout << "\n=== Testing Take Damage ===" << std::endl;
	clap2.takeDamage(3);
	clap2.takeDamage(4);
	clap2.takeDamage(5);
	
	std::cout << "\n=== Testing Actions on Dead ClapTrap ===" << std::endl;
	clap2.attack("Someone");
	clap2.takeDamage(1);
	clap2.beRepaired(5);
	
	std::cout << "\n=== Testing Repair Function ===" << std::endl;
	clap3.takeDamage(5);
	clap3.beRepaired(3);
	clap3.beRepaired(8);
	
	std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::stringstream ss;
		ss << "Target" << (i + 4);
		clap1.attack(ss.str());
	}
	
	clap1.beRepaired(1);
	clap1.beRepaired(1);
	clap1.attack("FinalTarget");
	
	std::cout << "\n=== Destructors will be called ===" << std::endl;
	return 0;
}

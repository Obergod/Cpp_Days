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

#include "DiamondTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "\n=== Creating DiamondTraps ===" << std::endl;
    DiamondTrap diamond1("DiamondOne");
    DiamondTrap diamond2("DiamondTwo");

    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    DiamondTrap diamond3(diamond1);

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    DiamondTrap diamond4("Temp");
    diamond4 = diamond2;

    std::cout << "\n=== Testing Attack Function (from ScavTrap) ===" << std::endl;
    diamond1.attack("TargetA");
    diamond2.attack("TargetB");

    std::cout << "\n=== Testing Take Damage and Repair ===" << std::endl;
    diamond1.takeDamage(40);
    diamond1.beRepaired(20);

    std::cout << "\n=== Testing whoAmI ===" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();
	diamond4.whoAmI();

    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::stringstream ss;
        ss << "Target" << (i + 1);
        diamond1.attack(ss.str());
    }

    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}

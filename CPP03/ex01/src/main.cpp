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

#include "ScavTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "\n=== Creating ScavTraps ===" << std::endl;
    ScavTrap scav1("Gatekeeper");
    ScavTrap scav2("Guardian");

    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    ScavTrap scav3(scav1);

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    ScavTrap scav4("Temp");
    scav4 = scav2;

    std::cout << "\n=== Testing Attack Function ===" << std::endl;
    scav1.attack("Intruder");
    scav2.attack("Enemy");

    std::cout << "\n=== Testing Take Damage and Repair ===" << std::endl;
    scav1.takeDamage(30);
    scav1.beRepaired(20);

    std::cout << "\n=== Testing guardGate ===" << std::endl;
    scav1.guardGate();
    scav2.guardGate();

    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::stringstream ss;
        ss << "Target" << (i + 1);
        scav1.attack(ss.str());
    }

    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}

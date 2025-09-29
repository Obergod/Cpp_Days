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

#include "FragTrap.hpp"
#include <sstream>

int main()
{
    std::cout << "\n=== Creating FragTraps ===" << std::endl;
    FragTrap frag1("Bomber");
    FragTrap frag2("Blaster");

    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    FragTrap frag3(frag1);

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    FragTrap frag4("Temp");
    frag4 = frag2;

    std::cout << "\n=== Testing Attack Function ===" << std::endl;
    frag1.attack("TargetA");
    frag2.attack("TargetB");

    std::cout << "\n=== Testing Take Damage and Repair ===" << std::endl;
    frag1.takeDamage(50);
    frag1.beRepaired(30);

    std::cout << "\n=== Testing highFivesGuys ===" << std::endl;
    frag1.highFivesGuys();
    frag2.highFivesGuys();

    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::stringstream ss;
        ss << "Target" << (i + 1);
        frag1.attack(ss.str());
    }

    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}

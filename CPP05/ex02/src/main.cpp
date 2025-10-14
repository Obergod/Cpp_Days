/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:54:34 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/07 17:54:35 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    srand(time(0)); 
    
    std::cout << "=== Basic Form Testing ===" << std::endl;
    
    try {
        Bureaucrat highLevel("Boss", 1);
        Bureaucrat midLevel("Manager", 50);
        Bureaucrat lowLevel("Intern", 150);
        
        std::cout << highLevel << std::endl;
        std::cout << midLevel << std::endl;
        std::cout << lowLevel << std::endl;
        
        PresidentialPardonForm pardon("Criminal");
        RobotomyRequestForm robotomy("Target");
        ShrubberyCreationForm shrubbery("garden");
        
        std::cout << "\n--- Presidential Pardon ---" << std::endl;
        highLevel.signForm(pardon);
        pardon.execute(highLevel);
        
        std::cout << "\n--- Robotomy Request ---" << std::endl;
        midLevel.signForm(robotomy);
        robotomy.execute(midLevel);
        
        std::cout << "\n--- Shrubbery Creation ---" << std::endl;
        lowLevel.signForm(shrubbery);
        shrubbery.execute(lowLevel);
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}

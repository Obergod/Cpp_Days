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

int main() 
{
    srand(time(0)); 
    
    std::cout << "=== Basic Form Testing ===" << std::endl;
    
    try {
        Bureaucrat highLevel("Boss", 1);        
        Bureaucrat midLevel("Manager", 40);    
        Bureaucrat lowLevel("Gardener", 130); 
        
        std::cout << highLevel << std::endl;
        std::cout << midLevel << std::endl;
        std::cout << lowLevel << std::endl;
        
        PresidentialPardonForm pardon("Criminal");
        RobotomyRequestForm robotomy("Target");
        ShrubberyCreationForm shrubbery("garden");
        
        std::cout << "\n--- Presidential Pardon ---" << std::endl;
        highLevel.signForm(pardon);         
        highLevel.executeForm(pardon);     
        
        std::cout << "\n--- Robotomy Request ---" << std::endl << std::endl; 
        highLevel.signForm(robotomy);     
        midLevel.executeForm(robotomy);  
		std::cout << std::endl;
        lowLevel.executeForm(robotomy);  
		std::cout << std::endl;
        
        std::cout << "\n--- Shrubbery Creation ---" << std::endl;
        lowLevel.signForm(shrubbery);   
        lowLevel.executeForm(shrubbery);
		std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}

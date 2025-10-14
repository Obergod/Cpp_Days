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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    srand(time(0));
    
    std::cout << "=== TESTING INTERN CLASS ===" << std::endl;
    
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat manager("Manager", 40);
    Bureaucrat gardener("Gardener", 130);
    
    std::cout << "\n--- Testing Valid Forms ---" << std::endl;
    
    AForm* form1 = someRandomIntern.makeForm("PresidentialPardonForm", "Alice");
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    std::cout << std::endl;
    
    AForm* form2 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    if (form2) {
        boss.signForm(*form2);
        manager.executeForm(*form2);
        delete form2;
    }
    
    std::cout << std::endl;
    
    AForm* form3 = someRandomIntern.makeForm("ShrubberyCreationForm", "garden");
    if (form3) {
        gardener.signForm(*form3);
        gardener.executeForm(*form3);
        delete form3;
    }
    
    std::cout << "\n--- Testing Invalid Forms ---" << std::endl;
    
    AForm* invalidForm1 = someRandomIntern.makeForm("NonExistentForm", "target");
    AForm* invalidForm2 = someRandomIntern.makeForm("InvalidForm", "target");
    AForm* invalidForm3 = someRandomIntern.makeForm("", "target");
    
    std::cout << "Invalid form 1: " << (invalidForm1 ? "Created" : "NULL") << std::endl;
    std::cout << "Invalid form 2: " << (invalidForm2 ? "Created" : "NULL") << std::endl;
    std::cout << "Invalid form 3: " << (invalidForm3 ? "Created" : "NULL") << std::endl;
    
    std::cout << "\n--- Testing Multiple Interns ---" << std::endl;
    
    Intern intern1;
    Intern intern2;
    
    AForm* form4 = intern1.makeForm("PresidentialPardonForm", "Bob");
    AForm* form5 = intern2.makeForm("RobotomyRequestForm", "Charlie");
    
    if (form4) {
        std::cout << "Intern 1 successfully created form" << std::endl;
        delete form4;
    }
    if (form5) {
        std::cout << "Intern 2 successfully created form" << std::endl;
        delete form5;
    }
    
    return 0;
}

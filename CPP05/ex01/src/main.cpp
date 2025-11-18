/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:54:34 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/18 16:38:20 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat Henry("Henry", 1);
		std::cout << std::endl << Henry;
		Henry.decGrade();
		std::cout << Henry << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Henry("Loser", 4);
		Form b("b", 3, 10);
		std::cout << std::endl;
		Henry.signForm(b);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Bureaucrat Henry("Ultra-boss", 1);
		Form b("b", 3, 10);
		std::cout << std::endl;
		Henry.signForm(b);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

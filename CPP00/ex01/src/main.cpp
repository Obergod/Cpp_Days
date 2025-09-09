/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:25 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/08 17:50:26 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	std::string line;
	PhoneBook	pb;
	int			i;
	int			index;

	i = 0;
	while (1)
	{
		std::cout << "\n     --- PHONEBOOK MENU ---" << std::endl;
		std::cout << "Enter command: ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, line);
		if (line == "EXIT")
			break ;
		else if (line == "ADD")
		{
			if (i == 8)
				i = 0;
			pb.add_contact(&i);
			std::cout << "Well played you know how to add a contact" << std::endl;
		}
		else if (line == "SEARCH")
		{
			if (pb.print_phonebook() == true)
			{
				std::cout << "Select index of contact" << std::endl;
				while (1)
				{
					std::getline(std::cin, line);
					if (valid_index(line, pb, &index))
					{
						pb.print_full_contact(index);
						break ;
					}
					else
						continue ;
				}
			}
		}
		else if (line.empty())
			continue ;
		else
			std::cout << "invalid command, try again" << std::endl;
		print_separator();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:18 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/08 17:50:18 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	add_i(std::string msg)
{
	std::string	line;

	while (1)
	{
		std::cout << msg << std::endl;
		std::getline(std::cin, line);
		if (line.empty())
			std::cout << "line can't be empty, try again :)" << std::endl;
		else
			break;
	}
	
	return (line);
}

void	PhoneBook::add_contact(PhoneBook pb, int *i)
{
	Contact new_contact(add_i("insert first name"), add_i("insert last name"),
			add_i("insert nickname"), add_i("insert phone number"),
			add_i("insert darkest secret"));
	pb.contacts[*i] = new_contact;
	(*i)++;
}

//continue doing phonebookprint
void	PhoneBook::print_phonebook(PhoneBook pb)
{
	int	i;

	i = 0;
	while (pb.contacts[i].is_empty() == false)
	{

	}
}


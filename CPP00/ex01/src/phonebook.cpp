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
#include <cstdlib>

PhoneBook::PhoneBook()
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

bool	is_number(const std::string &str)
{
	for(int i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	valid_index(const std::string &str, const PhoneBook &pb, int *index)
{
	int	nb;

	if (!is_number(str))
	{
		std::cout << "Not a number, try again" << std::endl;
		return (false);
	}
	nb = atoi(str.c_str());
	if (nb < 0 || nb > 7)
	{
		std::cout << "Invalid index, try again" << std::endl;
		return (false);
	}
	if (!pb.contact_exists(nb))
	{
		std::cout << "Contact does not exist, try again" << std::endl;
		return (false);
	}
	*index = nb;
	return (true);
}

void	print_separator()
{
	std::cout << "\n" << std::string(50, '-') << "\n";
}

std::string	add_i(std::string msg)
{
	std::string	line;

	while (1)
	{
		std::cout << msg << std::endl;
		std::getline(std::cin, line);
		if (line.empty())
			std::cout << "line can't be empty, try again :)" << std::endl;
		else if
			(msg == "insert phone number" && !is_number(line))
				std::cout << "Not a number try again" << std::endl;
		else
			break;
	}
	
	return (line);
}

void	PhoneBook::add_contact(int *i)
{
	Contact new_contact(add_i("insert first name"), add_i("insert last name"),
			add_i("insert nickname"), add_i("insert phone number"),
			add_i("insert darkest secret"));
	this->contacts[*i] = new_contact;
	(*i)++;
}

bool	PhoneBook::print_phonebook()
{
	int	i;

	i = 0;
	if (this->contacts[0].is_empty() == true)
	{
		std::cout << "No contacts yet :(" << std::endl;
		return false;
	}
	while (i < 8 && this->contacts[i].is_empty() == false)
	{
		this->contacts[i].print_info(i);
		i++;
	}
	return (true);
}


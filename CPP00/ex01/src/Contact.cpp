/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:06 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/08 17:50:07 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool	Contact::is_empty()
{
	if (this->first_name.empty())
		return (true);
	else
		return (false);
}

void	Contact::print_info(Contact contact, int i)
{
	std::cout << i << "." << std::endl << "|\n";
	if (contact.first_name.size() > 10)
	{
		contact.first_name.resize(10, '.');
	}
	std::cout << first_name << std::endl << "|\n";
	if (contact.last_name.size() > 10)
	{
		contact.last_name.resize(10, '.');
	}
	std::cout << last_name << std::endl << "|\n";
	if (contact.nickname.size() > 10)
	{
		contact.nickname.resize(10, '.');
	}
	std::cout << nickname << std::endl << "|\n";
}

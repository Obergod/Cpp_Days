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

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_nb = "";
	this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_nb, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_nb = phone_nb;
	this->darkest_secret = darkest_secret;
}

bool	Contact::is_empty() const
{
	if (this->first_name.empty())
		return (true);
	else
		return (false);
}

void	Contact::print_info(int i)
{
	std::string	trunc;
	
	std::cout << std::setw(2) <<  i << "." << " |";
	if (this->first_name.size() > 10)
	{
		trunc = this->first_name.substr(0, 9);
		std::cout << std::setw(10) << trunc << '.' << " |";
	}
	else
		std::cout << std::setw(10) << this->first_name << " |";
	if (this->last_name.size() > 10)
	{
		trunc = this->last_name.substr(0, 9);
		std::cout << std::setw(10) << trunc << '.' << " |";
	}
	else
		std::cout << std::setw(10) << this->last_name << " |";
	if (this->nickname.size() > 10)
	{
		trunc = this->nickname.substr(0, 9);
		std::cout << std::setw(10) << trunc << '.' << " |\n";
	}
	else
		std::cout << std::setw(10) << nickname << " |\n";
}

void	Contact::print_full_details()
{
	std::cout << "contacts info :" << std::endl;
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phone_nb << std::endl;
	std::cout << this->darkest_secret << std::endl;
}

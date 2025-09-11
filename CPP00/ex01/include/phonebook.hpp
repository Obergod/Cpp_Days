/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:57:27 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/05 19:57:28 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(int *i);
		bool	print_phonebook();
		bool	contact_exists(int i) const {return !this->contacts[i].is_empty();};
		void	print_full_contact(int index) {this->contacts[index].print_full_details();};
};


void	print_separator();
bool	valid_index(const std::string &str, const PhoneBook &pb, int *index);

#endif

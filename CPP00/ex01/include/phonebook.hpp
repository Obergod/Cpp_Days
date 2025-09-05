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

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:57:45 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/05 19:57:47 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nb;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();
		Contact(std::string	first_name, std::string	last_name, std::string nickname, std::string phone_nb, std::string darkest_secret);
		void	print_info(int i);
		bool	is_empty() const;
		void	print_full_details();
};



#endif

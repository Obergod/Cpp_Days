/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:22:05 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/24 17:22:07 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
		std::string levels[4];
	public:
		Harl();
		~Harl();
		void complain(std::string level);
		void (Harl::*f[4])(void);
};


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:50:45 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 21:29:20 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <string>
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Base
{
	private:

	public:
		virtual ~Base();
		
	
};

Base	*generate();
void	identify( Base* p );
void	identify( Base& p );






#endif


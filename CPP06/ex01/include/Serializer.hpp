/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:47:54 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 19:28:03 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "Data.hpp"
#include <stdint.h>


class Serializer	
{
	private:
		Serializer();
		Serializer( const Serializer &other );
		Serializer &operator=( const Serializer &other );
		~Serializer();
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};








#endif

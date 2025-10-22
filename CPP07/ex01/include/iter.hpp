/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:08:43 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/22 18:51:25 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

template <typename T>
void	iter(uintptr_t addres, unsigned int arrayL, void (*f)(T&))
{
	T	*ptr = reinterpret_cast<T*>(addres);
	for (unsigned int i = 0; i < arrayL; i++)
	{
		f(ptr[i]);
	}

}

template <typename T>
void iter(uintptr_t addres, unsigned int arrayL, void (*f)(const T&))
{
    T *ptr = reinterpret_cast<T*>(addres);
    for (unsigned int i = 0; i < arrayL; i++)
    {
        f(ptr[i]);
    }
}









#endif

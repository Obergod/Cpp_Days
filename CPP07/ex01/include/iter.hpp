/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:08:43 by mafioron          #+#    #+#             */
/*   Updated: 2026/01/14 18:15:27 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

template <typename T>
void	iter(T *ptr, unsigned int arrayL, void (*f)(T&))
{
	for (unsigned int i = 0; i < arrayL; i++)
	{
		f(ptr[i]);
	}

}

template <typename T>
void iter(T *ptr, unsigned int arrayL, void (*f)(const T&))
{
    for (unsigned int i = 0; i < arrayL; i++)
    {
        f(ptr[i]);
    }
}









#endif

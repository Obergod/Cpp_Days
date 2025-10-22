/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:15:59 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/22 18:52:27 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static uintptr_t serialize(void *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

static uintptr_t serialize(const void *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

void printInt(int& x) 
{
    std::cout << x << " ";
}

void printChar(char& c) 
{
    std::cout << c;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Numbers: ";
    ::iter(serialize(numbers), 5, printInt);
    std::cout << std::endl;
    
    const char word[] = {'H', 'e', 'l', 'l', 'o'};
    std::cout << "Word: ";
    ::iter(serialize(word), 5, printChar);
    std::cout << std::endl;
    
    return 0;
}

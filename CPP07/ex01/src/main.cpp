/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:15:59 by mafioron          #+#    #+#             */
/*   Updated: 2026/01/15 15:43:39 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> 
void print(T const & x)
{
	std::cout << x << std::endl;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4};
    std::cout << "Numbers: " << std::endl;
    iter(arr, 5, print<int>);
    std::cout << std::endl;

    const char word[] = {'H', 'e', 'l', 'l', 'o'};
    std::cout << "Word: " << std::endl;
    ::iter(word, 5, print<char>);
}

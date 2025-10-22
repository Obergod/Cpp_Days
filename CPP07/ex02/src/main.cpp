/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:47:58 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/22 20:54:01 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        Array<int> empty;
        std::cout << "Empty size: " << empty.size() << std::endl;
        
        Array<int> arr(5);
        std::cout << "Array size: " << arr.size() << std::endl;
        
        for (unsigned int i = 0; i < arr.size(); i++) 
		{
            arr[i] = i * 10;
        }
        
        std::cout << "Values: ";
        for (unsigned int i = 0; i < arr.size(); i++) 
		{
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        
        Array<int> copy(arr);
        copy[0] = 999;
        std::cout << "Original[0]: " << arr[0] << ", Copy[0]: " << copy[0] << std::endl;
        
        Array<int> assigned = copy;
        assigned[1] = 888;
        std::cout << "Copy[1]: " << copy[1] << ", Assigned[1]: " << assigned[1] << std::endl;
        
        std::cout << "Testing out of bounds..." << std::endl;
        std::cout << arr[10] << std::endl;  
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}

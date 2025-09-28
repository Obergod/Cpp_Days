/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:43:37 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/24 20:43:38 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    std::cout << "=== BSP Triangle Test Cases ===" << std::endl;
    
    Point a(0.0f, 0.0f);      
    Point b(4.0f, 0.0f);        
    Point c(2.0f, 3.0f);      
    
    std::cout << "Triangle vertices: A(0,0), B(4,0), C(2,3)" << std::endl;
    
    Point inside(2.0f, 1.0f);
    std::cout << "Point (2,1) inside triangle: " << (bsp(a, b, c, inside) ? "TRUE" : "FALSE") << std::endl;
    
    Point outside(5.0f, 5.0f);
    std::cout << "Point (5,5) inside triangle: " << (bsp(a, b, c, outside) ? "TRUE" : "FALSE") << std::endl;
    
    Point vertex(0.0f, 0.0f);
    std::cout << "Point on vertex A(0,0): " << (bsp(a, b, c, vertex) ? "TRUE" : "FALSE") << std::endl;
    
    Point edge(2.0f, 0.0f);   
    std::cout << "Point on edge (2,0): " << (bsp(a, b, c, edge) ? "TRUE" : "FALSE") << std::endl;
    
    Point closeInside(2.0f, 0.1f);
    std::cout << "Point close inside (2,0.1): " << (bsp(a, b, c, closeInside) ? "TRUE" : "FALSE") << std::endl;
    
    Point closeOutside(2.0f, -0.1f);
    std::cout << "Point close outside (2,-0.1): " << (bsp(a, b, c, closeOutside) ? "TRUE" : "FALSE") << std::endl;
    
    std::cout << "\n=== Expected Results ===" << std::endl;
    std::cout << "Inside: TRUE" << std::endl;
    std::cout << "Outside: FALSE" << std::endl;
    std::cout << "On vertex: FALSE" << std::endl;
    std::cout << "On edge: FALSE" << std::endl;
    std::cout << "Close inside: TRUE" << std::endl;
    std::cout << "Close outside: FALSE" << std::endl;
    
    return 0;
}

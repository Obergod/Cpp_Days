/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:41:31 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/31 18:11:45 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//int	main()
//{
//	Span sp = Span(5);
//
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//
//	return 0;
//}
//
#include "Span.hpp"

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

int main( void ) {

    try {
        
		Span span1 = Span( 50 );
		span1.addNumber( 6 );
		span1.addNumber( 3 );
		span1.addNumber( 17 );
		span1.addNumber( 9 );
		span1.addNumber( 11 );


		std::cout << "shortest : " << span1.shortestSpan() << std::endl;
		std::cout << "longuest : " << span1.longestSpan() << std::endl;
	}
    catch ( std::exception &e ) {
	
    	std::cerr << e.what() << std::endl;
	}

    try {

		Span span2 = Span( 0 );


		std::cout << "shortest : " << span2.shortestSpan() << std::endl;
		std::cout << "You should not see me" << std::endl;

	}
    catch ( std::exception &e ) {
    
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << std::endl;

    try {
        
		Span span3 = Span( 1 );
        span3.addNumber( 1 );
        span3.addNumber( 2 );

		std::cout << "You should not see me" << std::endl;
        
	}
    catch ( std::exception &e ) {
        
		std::cerr << e.what() << std::endl;
	}

    std::cout << std::endl;

    try {
		Span span5 = Span( 1000001 );
        std::vector<int> insert;
        
        for (int i = 0; i < 1000000; i++)
            insert.push_back( i );
        span5.addNumbers(insert);
		std::cout << "shortest : " << span5.shortestSpan() << std::endl;
		std::cout << "longuest : " << span5.longestSpan() << std::endl;
	}
    catch ( std::exception &e ) {
	
    	std::cerr << e.what() << std::endl;
	}

	return ( 0 );
}

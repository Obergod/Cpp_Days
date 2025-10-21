/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:24:32 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 21:40:57 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Letters.hpp"

int	main()
{
	srand(time(0));

	Base *a = generate();
	Base *b = generate();
	Base *c = generate();

	identify(a);
	identify(*a);
	identify(b);
	identify(*b);
	identify(c);
	identify(*c);

	delete a;
	delete b;
	delete c;
}

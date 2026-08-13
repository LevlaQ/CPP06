/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:27:02 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/13 17:29:52 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base * generate(void)
{
	Base	*ptr;
	const int random_value = std::rand();
	switch (random_value % 3)
	{
		case 0:
			ptr = new A();
			break;
		case 1:
			ptr = new B();
			break;
		case 2:
			ptr = new C();
	}
	return (ptr);
}

static void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This class is type A, as in ptr" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This class is type B, as in ptr" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This class is type C, as in ptr" << std::endl;
}
static void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "This class is type A, as in reference" << std::endl;
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "This class is type B , as in reference" << std::endl;
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "This class is type C , as in reference" << std::endl;
	}
	catch(...)
	{}
}

int	main(void)

{
	std::srand(std::time(NULL));

	Base	*first_class = generate();
	Base	*second_class = generate();
	Base	*third_class = generate();
	Base	*fourth_class = generate();
	Base	*fifth_class = generate();
	Base	*sixth_class = generate();
	
	identify(first_class);
	identify(*first_class);
	identify(second_class);
	identify(*second_class);
	identify(third_class);
	identify(*third_class);
	identify(fourth_class);
	identify(*fourth_class);
	identify(fifth_class);
	identify(*fifth_class);
	identify(sixth_class);
	identify(*sixth_class);

	delete first_class;
	delete second_class;
	delete third_class;
	delete fourth_class;
	delete fifth_class;
	delete sixth_class;
}
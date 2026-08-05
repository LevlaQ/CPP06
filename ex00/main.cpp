/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:30 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/05 21:44:06 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <typeinfo>

int	main(int ac, char **ag)
{
	
	if (ac != 2)
	{
		std::cout << "Proper usage: ./<program> <literal>" << std::endl;
		return (1);
	}
	std::string	literal = ag[1];

	// char	*end;
	// std::strtod("f.", &end);
	// std::cout << *end << std::endl;
	// std::cout << typeid(*end).name() << std::endl;
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::strtod("nan", 0)) << std::endl;
	try
	{
		ScalarConverter::converter(literal);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
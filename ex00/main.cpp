/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:30 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/08 18:33:31 by gyildiz          ###   ########.fr       */
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
	try
	{
		ScalarConverter::converter(literal);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

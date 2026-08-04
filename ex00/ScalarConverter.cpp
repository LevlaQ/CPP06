/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:13 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/04 20:03:52 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructer called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
	
	std::cout << "ScalarConverter copy constructer called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void)assign;
	
	std::cout << "ScalarConverter copy assign operator called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructer called" << std::endl;
}

const char	*ScalarConverter::ImproperLiteral::what() const throw()
{
	return ("Literal you have used is improper");
}

static void	isStringSpace(int str_length, char *&end, s_Scalar &scalar)
{
	if (str_length > 1)
	{
		if (scalar.c_string[0] == ' ' || *end == ' ')
			throw ScalarConverter::ImproperLiteral();
	}
}

static void	syntax_check(std::string &literal, s_Scalar &scalar)
{
	char	*end;
	int		str_length = literal.length();

	if (str_length == 0)
		throw	ScalarConverter::ImproperLiteral();
	scalar.c_string = literal.c_str();
	scalar.value = std::strtod(scalar.c_string, &end);

	isStringSpace(str_length, end, scalar);
	if (*end != '\0')
	{
		if (str_length > 1)
		{
			if(*end == 'f')
			{
				if(*(end + 1) != '\0')
					throw ScalarConverter::ImproperLiteral();
			}
			else
				throw ScalarConverter::ImproperLiteral();
		}
		else
			if (!std::isprint(*end))
				std::cout << "Char: Not displayable" << std::endl;
	}
}

static void isPseudo(std::string &literal, s_Scalar &scalar)
{
	if (literal == "inf" || literal == "+inf" || literal == "inff" ||\
		literal == "+inff")
		scalar.type = P_INF;
	else if (literal == "-inf" || literal == "-inff")
		scalar.type = N_INF;
	else if (literal == "nan" || literal == "nanf")
		scalar.type = NAN;
	else
		scalar.type = REAL;
}


void	ScalarConverter::converter(std::string &literal)
{
	s_Scalar	scalar;

	isPseudo(literal, scalar);
	//Eğer real ise syntax check yapılacak
	syntax_check(literal, scalar);
	
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:13 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/11 16:41:34 by gyildiz          ###   ########.fr       */
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

static int	count(const std::string &literal, char target)
{
	int	count = 0;
	
	for (size_t i = 0 ; i < literal.length() ; i++)
	{
		if (literal[i] == target)
			count++;
	}
	return (count);
}

static void	isStringSpace(int str_length, char *&end, s_Scalar &scalar)
{
	if (str_length > 1)
	{
		if (scalar.c_string[0] == ' ' || *end == ' ')
			throw ScalarConverter::ImproperLiteral();
	}
}

static void	type_check(const std::string &literal, char target, s_Scalar &scalar)
{
	isPseudo(literal, scalar);
}

static void	syntax_check(const std::string &literal, s_Scalar &scalar)
{
	char	*end;
	 
	scalar.str_length = literal.length();
	if (scalar.str_length == 0)
		throw	ScalarConverter::ImproperLiteral();
	scalar.c_string = literal.c_str();
	scalar.value = std::strtod(scalar.c_string, &end);
	isStringSpace(scalar.str_length, end, scalar);
	if (*end != '\0')
	{
		if (scalar.str_length > 1)
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
			scalar.value = static_cast<double>(*end);
	}
}

static void isPseudo(const std::string &literal, s_Scalar &scalar)
{
	if (literal == "inf" || literal == "+inf" || literal == "inff" ||\
		literal == "+inff")
		scalar.p_type = P_INF;
	else if (literal == "-inf" || literal == "-inff")
		scalar.p_type = N_INF;
	else if (literal == "nan" || literal == "nanf")
		scalar.p_type = N_NAN;
	else
		scalar.p_type = REAL;
}

static void printChar(s_Scalar &scalar)
{
	if (scalar.p_type != REAL || !(scalar.value >= 0 && scalar.value <= 250))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(scalar.value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(scalar.value) << std::endl;
}
static void printInt(s_Scalar &scalar)
{
	if (scalar.p_type != REAL)
		std::cout << "int: impossible" << std::endl;
	else if (scalar.value > INT_MAX || scalar.value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(scalar.value) << std::endl;
}
static void printFloat(s_Scalar &scalar)
{	
	std::cout << "float: ";
	switch (scalar.p_type)
	{
		case P_INF:
			std::cout << "inff" << std::endl;
			break;
		case N_INF:
			std::cout << "-inff" << std::endl;
			break;
		case N_NAN:
			std::cout << "nanf" << std::endl;
			break;
		default:
			std::cout << std::fixed << std::setprecision(1) << \
			static_cast<float>(scalar.value) << "f" << std::endl;
			break;
	}
	
}


static void printDouble(s_Scalar &scalar)
{
	std::cout << "double: ";
	switch (scalar.p_type)
	{
		case P_INF:
			std::cout << "inf" << std::endl;
			break;
		case N_INF:
			std::cout << "-inf" << std::endl;
			break;
		case N_NAN:
			std::cout << "nan" << std::endl;
			break;
		default:
			std::cout << std::fixed << std::setprecision(1) << \
			static_cast<float>(scalar.value) << std::endl;
			break;
	}
}


void	ScalarConverter::converter(std::string &literal)
{
	s_Scalar	scalar;

	isPseudo(literal, scalar);
	if (scalar.p_type == REAL)
		syntax_check(literal, scalar);
	printChar(scalar);
	printInt(scalar);
	printFloat(scalar);
	printDouble(scalar);
}
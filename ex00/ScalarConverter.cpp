/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:13 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/11 21:07:27 by gyildiz          ###   ########.fr       */
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

/*
	Are there any whitespces in the string that we are sure it is numeral?
	If there are any whitepaces returns 0
*/
static int isWhiteSpace_string(const std::string &literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (std::strchr(WS, literal[i]))
			return (0);
	}
	return(1);
}

static int isTruly_numeral(const std::string &literal)
{
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (std::isprint(static_cast<int>(literal[i])))
		{
			if (!std::isdigit(static_cast<int>(literal[i])) &&\
			 !std::strchr(SIGN, literal[i]))
				return (0);
		}
	}
	return (1);
}

/*
	Is the literal size 0? If it is not these special chars such as
	f, ., + and - must occur only once in the string.

	And then we are checking these special chars' positions.

	And there must be no white_space in the number literal
*/
static void	syntax_check_for_num(const std::string &literal)
{
	if (literal.size() == 0 )
		throw ScalarConverter::ImproperLiteral();
	else if (!isTruly_numeral(literal) || !isWhiteSpace_string(literal))
		throw ScalarConverter::ImproperLiteral();
	else if (count(literal, 'f') > 1 ||\
	 count(literal, '.') > 1 || count(literal, '+') > 1 \
	 || count(literal, '-') > 1)
		throw ScalarConverter::ImproperLiteral();
	else if ((literal.find('f') != std::string::npos) && \
	literal[literal.size() - 1] != 'f')
		throw ScalarConverter::ImproperLiteral();
	else if ((literal.find('+') != std::string::npos) && \
	literal[0] != '+')
		throw ScalarConverter::ImproperLiteral();
	else if ((literal.find('-') != std::string::npos) && \
	literal[0] != '-')
		throw ScalarConverter::ImproperLiteral();
}

static void	type_check(const std::string &literal, s_Scalar &scalar)
{
	if (literal.size() == 1 &&\
	 !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		scalar.l_type = CHAR;
		return;
	}
	
	/*
		From that point on, the string is either empty or a string with
		multiple chars, now we are dealing with numbers.
	*/

	syntax_check_for_num(literal);

	bool hasDot = literal.find('.') != std::string::npos;
	bool hasF   = !literal.empty() && literal[literal.size() - 1] == 'f';
	
	if (hasDot && hasF)
		scalar.l_type = FLOAT;
	else if (hasDot && !hasF)
		scalar.l_type = DOUBLE;
	else if (!hasDot && !hasF)
		scalar.l_type = INT;
	else
		throw ScalarConverter::ImproperLiteral();
}

static void isPseudo(const std::string &literal, s_Scalar &scalar)
{
	if (literal == "inf" || literal == "+inf" || literal == "inff" ||\
		literal == "+inff")
		scalar.l_type = P_INF;
	else if (literal == "-inf" || literal == "-inff")
		scalar.l_type = N_INF;
	else if (literal == "nan" || literal == "nanf")
		scalar.l_type = N_NAN;
	else
		return;
}


static void printChar(const std::string &literal)
{
	// if (scalar.l_type != REAL || !(scalar.value >= 0 && scalar.value <= 250))
	// 	std::cout << "char: impossible" << std::endl;
	// else if (!std::isprint(static_cast<int>(scalar.value)))
	// 	std::cout << "char: Non displayable" << std::endl;
	// else
	// 	std::cout << "char: " << static_cast<char>(scalar.value) << std::endl;
}

static void printInt(const std::string &literal)
{
	// if (scalar.l_type != REAL)
	// 	std::cout << "int: impossible" << std::endl;
	// else if (scalar.value > INT_MAX || scalar.value < INT_MIN)
	// 	std::cout << "int: impossible" << std::endl;
	// else
	// 	std::cout << "int: " << static_cast<int>(scalar.value) << std::endl;
}

static void printFloat(const std::string &literal)
{	
	// std::cout << "float: ";
	// switch (scalar.l_type)
	// {
	// 	case P_INF:
	// 		std::cout << "inff" << std::endl;
	// 		break;
	// 	case N_INF:
	// 		std::cout << "-inff" << std::endl;
	// 		break;
	// 	case N_NAN:
	// 		std::cout << "nanf" << std::endl;
	// 		break;
	// 	default:
	// 		std::cout << std::fixed << std::setprecision(1) << \
	// 		static_cast<float>(scalar.value) << "f" << std::endl;
	// 		break;
	// }
	
}

static void printDouble(const std::string &literal)
{
	// std::cout << "double: ";
	// switch (scalar.l_type)
	// {
	// 	case P_INF:
	// 		std::cout << "inf" << std::endl;
	// 		break;
	// 	case N_INF:
	// 		std::cout << "-inf" << std::endl;
	// 		break;
	// 	case N_NAN:
	// 		std::cout << "nan" << std::endl;
	// 		break;
	// 	default:
	// 		std::cout << std::fixed << std::setprecision(1) << \
	// 		static_cast<float>(scalar.value) << std::endl;
	// 		break;
	// }
}

static void print_pseudo_literal\
(const std::string &literal, s_Scalar &ScalarConverter)
{
	
}

void	ScalarConverter::converter(std::string &literal)
{
	s_Scalar	scalar;

	isPseudo(literal, scalar);
	if (scalar.l_type > N_NAN)
		type_check(literal, scalar);
	switch (scalar.l_type)
	{
		case CHAR:
			printChar(literal);
			break;
		case INT:
			printInt(literal);
			break;
		case DOUBLE:
			printDouble(literal);
			break;
		case FLOAT:
			printFloat(literal);
			break;
		default:
			print_pseudo_literal(literal, scalar);
	}
}
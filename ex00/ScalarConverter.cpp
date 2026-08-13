/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:13 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/13 15:02:10 by gyildiz          ###   ########.fr       */
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

const char	*ScalarConverter::StreamError::what() const throw()
{
	return ("An error occured with String stream");
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
	else if ((literal.find('f') != std::string::npos) && \
	!std::isdigit(static_cast<int>(literal[literal.size() - 2])))
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

/*
	If the program is not pseudo_literal, then we assign a temp CHAR
	enum to tell the program we are dealing with another type of string.
*/
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
		scalar.l_type = CHAR;
}


static void printChar(const std::string &literal)
{
	std::stringstream ss(literal);
	char c;
	ss >> c;

	if (ss.fail())
		throw ScalarConverter::StreamError();

	// Printing the char
	if (!std::isprint(static_cast<int>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
	
	// Print the int from char
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	// Print the double from char
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << \
	static_cast<double>(c) << std::endl;

	// Print the float from char
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << \
	static_cast<float>(c) << "f" << std::endl;
	
}

static void printInt(const std::string &literal)
{
	double i;

	i = std::strtod(literal.c_str(), NULL);

	// Printing char from int
	if (!(static_cast<int>(i) >= 0 && static_cast<int>(i) <= 250))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;

	// Printing int
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;

	// Print double
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << \
	static_cast<double>(i) << std::endl;

	// Print float
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << \
	static_cast<float>(i) << "f" << std::endl;
	
}

/*
	strtod() usage is a must
*/
static void printDouble(const std::string &literal)
{
	double d;

	d = std::strtod(literal.c_str(), NULL);

	// Print char from double
	if (!(static_cast<int>(d) >= 0 && static_cast<int>(d) <= 250))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
	
	// Print int from double
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// Print double
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << \
	d << std::endl;
	
	// Print float
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << \
	static_cast<float>(d) << "f" << std::endl;
}

static void printFloat(const std::string &literal)
{	
	std::stringstream ss(literal);
	float f;
	ss >> f;
	
	if (ss.fail())
		throw ScalarConverter::StreamError();

	// Print char from float
	if (!(static_cast<int>(f) >= 0 && static_cast<int>(f) <= 250))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;

	// Print int from float
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	// Print double from float
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << \
	static_cast<double>(f) << std::endl;

	// Print float
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << \
	f << "f" << std::endl;
}

static void print_pseudo_literal(s_Scalar &ScalarConverter)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	switch (ScalarConverter.l_type)
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
			std::cout << "??" << std::endl;
	}
	std::cout << "double: ";
	switch (ScalarConverter.l_type)
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
			std::cout << "??" << std::endl;
	}
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
			print_pseudo_literal(scalar);
	}
}
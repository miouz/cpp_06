#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

double value;

double	parseInput(const std::string& literal)
{
	std::string	specialFloatLiterals[4] = {"-inff", "inff", "+inff","nanf"};
	std::string	specialDoubleLiterals[4] = {"-inf", "inf", "+inf","nan"};
	double	SpecialDoubles[4] = {-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(), std::numeric_limits<double>::quiet_NaN()};

	//if is special literals
	for (int i = 0; i < 4; i++)
	{
		if (literal == specialFloatLiterals[i]
			|| literal == specialDoubleLiterals[i])
			return SpecialDoubles[i];
	}

	char *endptr;
	errno = 0;
	double result = std::strtod(literal.c_str(), &endptr);
	if (*endptr == 'f')
		endptr++;
	while (std::isspace(*endptr) == true)
		endptr++;
	if (*endptr != '\0' || endptr == literal.c_str())
		throw std::invalid_argument("Conversion impossible: Argument not valid");
	if (errno == ERANGE)
		throw std::invalid_argument("Overflow or underflow occurred");
	return result;
}

void ScalarConverter::convert(const std::string& literal)
{
	value = parseInput(literal);

}

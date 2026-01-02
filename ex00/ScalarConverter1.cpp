#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

double value;

Type	literalType;

double	specialDoubles[4] = {-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
	std::numeric_limits<double>::infinity(), std::numeric_limits<double>::quiet_NaN()};

Type	parseInput(const std::string& literal)
{
	std::string	specialLiterals[8] = {"-inff", "inff", "+inff","nanf",
		"-inf", "inf", "+inf","nan"};
	Type type[8] = {FLOAT_TYPE, FLOAT_TYPE, FLOAT_TYPE, FLOAT_TYPE,
		DOUBLE_TYPE, DOUBLE_TYPE, DOUBLE_TYPE, DOUBLE_TYPE};

	//if is special literals
	for (int i = 0; i < 4; i++)
	{
		if (literal == specialLiterals[i])
		{
			value = specialDoubles[i % 4];
			return type[i];
		}
	}

	char *endptr;
	errno = 0;
	u_value.dVal = std::strtod(literal.c_str(), &endptr);
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
	literalType = getType(literal);
	value = parseInput(literal);

}

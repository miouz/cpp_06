#include "ScalarConverter.hpp"
#include <limits>

static double	getSpecialValue(const std::string& literal)
{
	std::string	specialLiterals[8] = {"-inff", "inff", "+inff","nanf",
		"-inf", "inf", "+inf","nan"};
	double	specialDoubles[4] = {-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(), std::numeric_limits<double>::quiet_NaN()};
	int i = 0;
	while(i < 8)
	{
		if (literal == specialLiterals[i])
			break;
		i++;
	}
	return specialDoubles[i % 4];
}

double	getValue(const std::string& literal, const Type& type) throw(std::invalid_argument)
{
	if (type == SPECIAL_TYPE)
		return getSpecialValue(literal);
	if (type == CHAR_TYPE)
		return literal[0];
	char *endptr;
	errno = 0;
	double	result = std::strtod(literal.c_str(), &endptr);
	if (*endptr == 'f')
		endptr++;
	if (*endptr != '\0' || endptr == literal.c_str()
		|| !(isdigit(literal[0])
			|| ((literal[0] == '+' || literal[0] == '-') && isdigit(literal[1]))))
		throw std::invalid_argument("Conversion impossible: Argument not valid");
	if (errno == ERANGE)
		throw std::invalid_argument("Overflow or underflow occurred");
	return result;
}


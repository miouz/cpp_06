#include "ScalarConverter.hpp"

static bool	isSpecialLiteral(const std::string& literal)
{
	std::string	specialLiterals[8] = {"-inff", "inff", "+inff","nanf",
		"-inf", "inf", "+inf","nan"};
	for (int i = 0; i < 8; i++)
	{
		if (literal == specialLiterals[i])
			return true;
	}
	return false;
}

Type	getType(const std::string& literal)
{
	if (isSpecialLiteral(literal))
		return SPECIAL_TYPE;
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return CHAR_TYPE;
	if (literal.find('.') != std::string::npos
		&& literal.find('f') == literal.size() - 1)
		return FLOAT_TYPE;
	if (literal.find('.') != std::string::npos)
		return DOUBLE_TYPE;
	return INT_TYPE;
}

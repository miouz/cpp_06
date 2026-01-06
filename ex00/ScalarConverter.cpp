#include "ScalarConverter.hpp"

//check error in literal's own type
void convertToType(const Type &type, const double& value)
{
	if (type == INT_TYPE)
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("Overflow or underflow occurred");
}

int getPrecision(const std::string& literal)
{
	int precision = literal.length() -1 - literal.find('.');
	if (literal[literal.length() - 1] == 'f')
		precision--;
	return precision;
}

void ScalarConverter::convert(const std::string& literal)
{
	double	value;
	Type	literalType = INT_TYPE;
	int		precision = 0;

	try{
	literalType = getType(literal);
	if (literalType == FLOAT_TYPE || literalType == DOUBLE_TYPE)
		precision = getPrecision(literal);
	value= getValue(literal, literalType);
	convertToType(literalType, value);
	displayInAllTypes(literalType, value, precision);
	}catch(...)
	{
		displayImpossible();
	}
}

#include "ScalarConverter.hpp"

//check error in literal's own type
void convertToType(const Type &type, const double& value)
{
	if (type == INT_TYPE)
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("Overflow or underflow occurred");
}

void ScalarConverter::convert(const std::string& literal)
{
	double	value;
	Type	literalType = INT_TYPE;

	try{
	literalType = getType(literal);
	value= getValue(literal, literalType);
	convertToType(literalType, value);
	displayInAllTypes(literalType, value);
	}catch(...)
	{
		displayImpossible();
	}
}

#ifndef SCALARCONVERT_HPP_
#define SCALARCONVERT_HPP_

#include <string>


enum Type
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	SPECIAL_TYPE,
	IMPOSSIBLE
};

class ScalarConverter
{
	private:
	ScalarConverter();

	public:
	static void convert(const std::string& literal);
};

Type	getType(const std::string& literal);
double	getValue(const std::string& literal, const Type& type) throw(std::invalid_argument);
void	displayInAllTypes(const Type& type, const double& value);
#endif // !SCALARCONVERT_HPP_

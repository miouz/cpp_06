#ifndef SCALARCONVERT_HPP_
#define SCALARCONVERT_HPP_

#include <string>


enum Type
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	IMPOSSIBLE
};

class ScalarConverter
{
	private:
	ScalarConverter();

	public:
	static void convert(const std::string& literal);
};

#endif // !SCALARCONVERT_HPP_

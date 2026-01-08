#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int random = rand() % 3;
	switch (random) {
		case 1:
			return new A;
		case 2:
			return new B;
		default:
			return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Points to Base derived A class\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Points to Base derived B class\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Points to Base derived C class\n";
	else
		std::cout << "Can not identify type\n";
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Referenced to Base derived A class\n";
		return ;
	} catch (...) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Referenced to Base derived B class\n";
		return ;
	} catch (...) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Referenced to Base derived C class\n";
		return ;
	} catch (...) { }
	std::cout << "Can not identify type\n";
}

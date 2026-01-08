#include "identify.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	srand(time(0));
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

}

void identify(Base& p)
{

}

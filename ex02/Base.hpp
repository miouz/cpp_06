#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <new>
#include <iostream>

class Base
{
	public:
	Base();
	virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
#endif // !BASE_HPP_

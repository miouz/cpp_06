#include "Base.hpp"

int main()
{
	srand(time(0));
	
	std::cout << "==============5 test for testing random, generate and identify==================\n";
	// test for generate and identify 
	Base* ptr = NULL;
	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;


	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;

	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;


	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;


	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;


	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;


	try {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
	} catch (std::exception& e) {
		std::cout <<"Error: " << e.what() << "\n"; 
	}
	delete ptr;
	ptr = NULL;

	std::cout << "==============test for NULL pointer==================\n";
	//test for NULL pointer 
	Base* ptr2 = NULL;

	identify(ptr2);
	return 0;
}

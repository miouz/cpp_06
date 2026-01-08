#include "Serializer.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	Data d = {53, '*'};
	Data* data = &d; 
	Data* nulPtr = NULL;

	uintptr_t addr = Serializer::serialize(data);
	uintptr_t addrNul = Serializer::serialize(nulPtr);
	Data* restore = Serializer::deserialize(addr);
	Data* restoreNul = Serializer::deserialize(addrNul);

	std::cout << "content of data is: " << data->iVal << " " << data->cVal << "\n";
	std::cout << "addr after serialized: " << addr << "\n";
	std::cout << "addrNul after serialized: " << addrNul << "\n";
	std::cout << "restore address after deserialized: " << restore << "\n";
	std::cout << "restore content after deserialized: " << restore->iVal <<" "<< restore->cVal << "\n";
	std::cout << "restoreNul after serialized: " << restoreNul << "\n";
	return 0;
}

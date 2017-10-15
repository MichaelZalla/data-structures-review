#include <iostream>
#include <stdexcept>

void assert(const char* conditionDescription, bool condition)
{

	if(!condition)
	{

		std::cout << "Condition not satisfied: " << conditionDescription << std::endl;

		throw std::runtime_error("Condition not satisfied!");

	}

	return;

}

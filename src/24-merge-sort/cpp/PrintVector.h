#ifndef PRINT_VECTOR_H
#define PRINT_VECTOR_H

#include <vector>
#include <iostream>

template <typename T>
void printVector(
	const std::vector<T>& collection)
{

	std::cout << "{";

	for(
		std::vector<int>::const_iterator pos = collection.begin();
		pos < collection.end();
		pos++)
	{

		std::cout << *pos;

		if(std::next(pos, 1) != collection.end())
		{
			std::cout << ",";
		}

	}

	std::cout << "}";

}

#endif

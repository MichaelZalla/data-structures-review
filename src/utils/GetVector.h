#ifndef GET_VECTOR_H
#define GET_VECTOR_H

#include <vector>

template <typename T>
std::vector<T> getVector(T* collection, int size)
{
	std::vector<T> result;

	if(sizeof(collection) != 0)
	{
		result = std::vector<T>(collection, collection + size);
	}

	return result;
}

#endif

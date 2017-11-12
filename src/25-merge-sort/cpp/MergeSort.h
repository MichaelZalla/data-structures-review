#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include "./Merge.h"

template <typename T>
std::vector<T> mergeSort(
	const std::vector<T>& collection)
{

	typedef typename std::vector<T>::const_iterator Iterator;

	Iterator begin = collection.begin();
	Iterator end = collection.end();

	int size = std::distance(begin, end);

	// Base case (size < 2)

	if(size < 2)
	{
		return std::vector<T>(collection);
	}

	// Recursive case

	Iterator middle = begin + (size / 2);

	std::vector<T> leftSorted =
		mergeSort(std::vector<T>(begin, middle));

	std::vector<T> rightSorted =
		mergeSort(std::vector<T>(middle, end));

	return merge(leftSorted, rightSorted);

}

#endif

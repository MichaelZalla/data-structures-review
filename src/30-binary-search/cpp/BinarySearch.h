#ifndef BINARY_SEARCH_ARRAY_H
#define BINARY_SEARCH_ARRAY_H

#include <cmath>

int binarySearch(
	int* sequence,
	int sequenceSize,
	int query,
	int leftIndex,
	int rightIndex)
{

	if(leftIndex > rightIndex)
	{
		return -1;
	}

	int midIndex = leftIndex + std::floor((float)(rightIndex - leftIndex) / 2);

	if(sequence[midIndex] == query)
	{
		return midIndex;
	}
	else if(sequence[midIndex] < query)
	{
		return binarySearch(sequence, sequenceSize, query, midIndex + 1, rightIndex);
	}
	else
	{
		return binarySearch(sequence, sequenceSize, query, leftIndex, midIndex - 1);
	}

}

int binarySearch(
	int* sequence,
	int sequenceSize,
	int query)
{

	int lastIndex = sequenceSize - 1;

	return binarySearch(sequence, sequenceSize, query, 0, lastIndex);
}

#endif

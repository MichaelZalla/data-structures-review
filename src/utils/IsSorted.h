#ifndef IS_SORTED_H
#define IS_SORTED_H

#include <vector>

template <typename T>
bool isSorted(
	const std::vector<T>& sequence)
{

	// Single-element sequences trivially satisfy the sort invariant;

	if(sequence.size() < 2)
	{
		return true;
	}

	// Check invariant by comparing contiguous elements in the sequence;

	for(
		typename std::vector<T>::const_iterator current = sequence.begin();
		current != --sequence.end();
		++current)
	{
		if(*(current+1) < *current)
		{
			return false;
		}
	}

	return true;

}

#endif

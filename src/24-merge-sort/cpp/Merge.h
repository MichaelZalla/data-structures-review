#ifndef MERGE_H
#define MERGE_H

#include <vector>

template <typename T>

std::vector<T> merge(
	const std::vector<T>& left,
	const std::vector<T>& right)
{

	typedef typename std::vector<T>::const_iterator Iterator;

	Iterator leftPos = left.begin();
	Iterator rightPos = right.begin();

	std::vector<T> merged;

	merged.reserve(left.size() + right.size());

	while(leftPos != left.end() && rightPos != right.end())
	{
		if(*leftPos <= *rightPos)
		{
			merged.push_back(*leftPos++);
		}
		else
		{
			merged.push_back(*rightPos++);
		}
	}

	while(leftPos != left.end())
	{
		merged.push_back(*leftPos++);
	}

	while(rightPos != right.end())
	{
		merged.push_back(*rightPos++);
	}

	return merged;

}

#endif

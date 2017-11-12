#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

#include "../../13-heap-priority-queue/HeapPriorityQueue.h"

template <typename T, typename C>
std::vector<T> heapSort(const std::vector<T>& collection, const C& comparator)
{

	typedef typename std::vector<T>::const_iterator ConstIterator;

	std::vector<T> result;
	HeapPriorityQueue<T,C> heap;

	for(
		ConstIterator pos = collection.begin();
		pos != collection.end();
		pos++)
	{
		heap.insert(*pos);
	}

	while(!heap.isEmpty())
	{
		result.push_back(heap.min());

		heap.removeMin();
	}

	return result;

}

#endif

#ifndef IN_PLACE_HEAP_SORT_H
#define IN_PLACE_HEAP_SORT_H

#include <iterator>
#include <algorithm>
#include <vector>

#include <iostream>

#include "../../assert.h"
#include "../../07-vector/PrintVector.h"

template <typename T, typename C>
void inPlaceHeapSort(
	std::vector<T>& collection,
	C isGreaterThan)
{

	typedef typename std::vector<T>::iterator Position;

	int size = collection.size();

	if(size < 2)
	{
		return;
	}

	Position begin = collection.begin();
	Position end = collection.end();

	Position boundary = std::next(begin);

	// First phase: For each element from index 1..n-1, insert the element into
	// the implicit heap structure on the left;

	while(boundary != end)
	{

		Position pos = boundary;

		// std::cout << "Adding " << *pos << " into the heap..." << std::endl;

		Position parent;

		// While pos is not the root...

		while(pos - begin > 0)
		{

			// Get the parent of pos
			parent = begin + ((pos - begin) - 1) / 2;

			// std::cout << (((pos - begin) - 1) / 2) << std::endl;

			// std::cout << "Parent of " << *pos << " is " << *parent << "." << std::endl;

			if(!isGreaterThan(*pos, *parent))
			{
				break;
			}

			// printVector(collection);
			// std::cout << std::endl;

			std::iter_swap(pos, parent);

			pos = parent;

		}

		// printVector(collection);
		// std::cout << std::endl;

		std::advance(boundary, 1);

	}

	// std::cout << "Finished heapify:" << std::endl;
	// printVector(collection);
	// std::cout << std::endl;

	// Second phase: Remove the maximum element from the heap (moving it to the
	// right) until the implicit heap structure is empty;

	assert("Boundary has reached the end!", boundary == collection.end());
	assert("Boundary has reached the end!", boundary == end);

	std::advance(boundary, -1);

	while(boundary != begin)
	{

		std::iter_swap(begin, boundary);

		Position pos = begin;

		// std::cout << "Removing " << *pos << " from the heap." << std::endl;

		Position child;
		Position leftChild = begin + 2 * (pos - begin) + 1;
		Position rightChild = begin + 2 * (pos - begin) + 2;

		// std::cout << "\tLeft child of " << *pos << " is " << *leftChild << "." << std::endl;
		// std::cout << "\tRight child of " << *pos << " is " << *rightChild << "." << std::endl;

		// Restore the max-heap property following the removal by swapping the
		// new root with its smallest child;

		while(leftChild < boundary)
		{

			if(rightChild < boundary && isGreaterThan(*rightChild, *leftChild))
			{
				child = rightChild;
			}
			else
			{
				child = leftChild;
			}

			if(!isGreaterThan(*child, *pos))
			{
				break;
			}

			std::iter_swap(pos, child);

			pos = child;

			leftChild = begin + 2 * (pos - begin) + 1;

			rightChild = begin + 2 * (pos - begin) + 2;

		}

		std::advance(boundary, -1);

	}

	// std::cout << "Finished de-heapify:" << std::endl;
	// printVector(collection);
	// std::cout << std::endl;

}

#endif

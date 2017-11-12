#include <iterator>
#include <vector>

#include "../../assert.h"

#include "../../13-heap-priority-queue/IntegerComparator.h"

#include "./HeapSort.h"

typedef std::vector<int> List;

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

int main(int argc, char** argv)
{

	int unsorted[] = {1,2,3,8,9,5,7,0,1,9,2,8,3,7,0,4};
	int sorted[] = {0,0,1,1,2,2,3,3,4,5,7,7,8,8,9,9};
	int count = sizeof(unsorted) / sizeof(unsorted[0]);

	List unsortedCollection = getVector(unsorted, sizeof(unsorted) / sizeof(int));

	IntegerComparator comparator;

	List sortedCollection = heapSort(unsortedCollection, comparator);

	assert("We can use the min-heap to sort in O(n log n) time.",
		sortedCollection == getVector(sorted, sizeof(sorted) / sizeof(int)));

	return 0;

}

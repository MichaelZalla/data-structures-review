#include <iterator>
#include <vector>

#include "../../utils/Assert.h"
#include "../../utils/GetVector.h"
#include "../../utils/PrintVector.h"
#include "../../13-heap-priority-queue/IntegerLessThanComparator.h"
#include "../../13-heap-priority-queue/IntegerGreaterThanComparator.h"

#include "./HeapSort.h"
#include "./InPlaceHeapSort.h"

typedef std::vector<int> List;

int main(int argc, char** argv)
{

	IntegerLessThanComparator ltComparator;
	IntegerGreaterThanComparator gtComparator;

	int unsorted[] = {1,2,3,8,9,5,7,0,1,9,2,8,3,7,0,4};

	int sorted[] = {0,0,1,1,2,2,3,3,4,5,7,7,8,8,9,9};

	int count = sizeof(unsorted) / sizeof(unsorted[0]);

	List unsortedCollection = getVector(unsorted, sizeof(unsorted) / sizeof(int));

	List sortedCollection = heapSort(unsortedCollection, ltComparator);

	assert("We can use the min-heap to sort in O(n log n) time.",
		sortedCollection == getVector(sorted, sizeof(sorted) / sizeof(int)));

	inPlaceHeapSort(unsortedCollection, gtComparator);

	assert("In place heap-sort", unsortedCollection == sortedCollection);

	return 0;

}

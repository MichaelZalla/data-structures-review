#include <vector>

#include "../../utils/Assert.h"
#include "../../utils/GetVector.h"
#include "../../utils/IsSorted.h"
#include "../../utils/PrintVector.h"

#include "./QuickSort.h"

int main(int argc, char** argv)
{

	// Test verification function

	int unsorted[] = {5,1,2,4,9,8,7,1,9};

	assert("The unsorted data set fails validation.",
		isSorted(
			getVector(unsorted, sizeof(unsorted) / sizeof(int))
		) == false);

	int sorted[] = {1,1,2,4,5,7,8,9,9};

	assert("The sorted data set passes validation.",
		isSorted(
			getVector(sorted, sizeof(sorted) / sizeof(int))
		) == true);

	// Quick-sort, base case: Empty sequence

	int dataset1[] = {};

	std::vector<int> dataset1Vector =
		getVector(dataset1, sizeof(dataset1) / sizeof(int));

	quickSort(dataset1Vector);

	assert("Sequence has been sorted.",
		isSorted(dataset1Vector));

	// Quick-sort, base case: 1-element sequence

	int dataset2[] = {7};

	std::vector<int> dataset2Vector =
		getVector(dataset2, sizeof(dataset2) / sizeof(int));

	quickSort(dataset2Vector);

	assert("Sequence has been sorted.",
		isSorted(dataset2Vector));

	// Quick-sort, simple recursive case: 3-element sequence

	int dataset3[] = {8,13,5};

	std::vector<int> dataset3Vector =
		getVector(dataset3, sizeof(dataset3) / sizeof(int));

	quickSort(dataset3Vector);

	assert("Sequence has been sorted.",
		isSorted(dataset3Vector));

	// Quick-sort, larger recursive case: 20-element sequence

	int dataset4[] = {7,58,9,71,2098,37,50,18263,1,5702,38975,9081,2,3480,97};

	std::vector<int> dataset4Vector =
		getVector(dataset4, sizeof(dataset4) / sizeof(int));

	quickSort(dataset4Vector);

	assert("Sequence has been sorted.",
		isSorted(dataset4Vector));

	return 0;

}

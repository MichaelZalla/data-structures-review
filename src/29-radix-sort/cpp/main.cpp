#include <iostream>
#include <vector>

#include "../../utils/cpp/Assert.h"
#include "../../utils/cpp/GetVector.h"
#include "../../utils/cpp/PrintVector.h"
#include "../../utils/cpp/IsSorted.h"

#include "./RadixSort.h"

int main(int argc, char** argv)
{

	// @TODO(mzalla) Where to store utility tests?

	// Test utility functions

	assert("getFirstDigit(0) == 0", getFirstDigit(0) == 0);
	assert("getFirstDigit(4) == 4", getFirstDigit(4) == 4);
	assert("getFirstDigit(12) == 2", getFirstDigit(12) == 2);
	assert("getFirstDigit(412) == 2", getFirstDigit(412) == 2);

	assert("getDigit(0,0) == 0", getDigit(0,0) == 0);
	assert("getDigit(4,0) == 4", getDigit(4,0) == 4);
	assert("getDigit(12,0) == 2", getDigit(12,0) == 2);
	assert("getDigit(12,1) == 1", getDigit(12,1) == 1);
	assert("getDigit(12,2) == 0", getDigit(12,2) == 0);
	assert("getDigit(412,0) == 2", getDigit(412,0) == 2);
	assert("getDigit(412,1) == 1", getDigit(412,1) == 1);
	assert("getDigit(412,2) == 4", getDigit(412,2) == 4);
	assert("getDigit(412,3) == 0", getDigit(412,3) == 0);

	assert("getDigit(1000,0) == 0", getDigit(1000,0) == 0);
	assert("getDigit(1000,1) == 0", getDigit(1000,1) == 0);
	assert("getDigit(1000,2) == 0", getDigit(1000,2) == 0);
	assert("getDigit(1000,3) == 1", getDigit(1000,3) == 1);
	assert("getDigit(1000,4) == 0", getDigit(1000,4) == 0);

	// Base case: Empty sequence

	int dataset1[] = {};

	std::vector<int> dataset1Vector =
		getVector(dataset1, sizeof(dataset1) / sizeof(int));

	radixSort(dataset1Vector);

	assert("1. Sequence is sorted.",
		isSorted(dataset1Vector));

	// Base case: One-element sequence

	int dataset2[] = {4};

	std::vector<int> dataset2Vector =
		getVector(dataset2, sizeof(dataset2) / sizeof(int));

	radixSort(dataset2Vector);

	assert("2. Sequence is sorted.",
		isSorted(dataset2Vector));

	// N-element sequence

	int dataset3[] = {8015,27,85,328,41,293,7,509,812};

	std::vector<int> dataset3Vector =
		getVector(dataset3, sizeof(dataset3) / sizeof(int));

	radixSort(dataset3Vector);

	assert("3. Sequence is sorted.",
		isSorted(dataset3Vector));

	// N-element sequence, cont.

	int dataset4[] = {10000,1000,100,10,1,0};

	std::vector<int> dataset4Vector =
		getVector(dataset4, sizeof(dataset4) / sizeof(int));

	radixSort(dataset4Vector);

	assert("4. Sequence is sorted.",
		isSorted(dataset4Vector));

}

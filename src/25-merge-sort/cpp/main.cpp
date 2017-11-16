#include <vector>
#include <iostream>

#include "../../utils/cpp/Assert.h"

#include "../../utils/cpp/PrintVector.h"
#include "./MergeSort.h"
#include "./Merge.h"

typedef std::vector<int> List;

int main(int argc, char** argv)
{

	assert("Merging two empty vectors yields an empty vector.",
		merge(List({}), List({})) ==
			List({}));

	assert("Merging two one-element vectors yields a sorted pair.",
		merge(List({94}), List({72})) ==
			List({72, 94}));

	assert("We can merge two sorted lists of arbitrary lengths.",
		merge(List({1,4,7}), List({0,3,9})) ==
		List({0,1,3,4,7,9}));

	assert("We can merge two sorted lists of different lengths.",
		merge(List({1,4}), List({3})) ==
		List({1,3,4}));

	assert("mergeSort yields a sorted list.",
		mergeSort(List({5,3})) ==
		List({3,5}));

	assert("mergeSort yields a sorted list.",
		mergeSort(List({3,5,1,9,7,5,9,2,3,8,4,0,1,2,3})) ==
		List({0,1,1,2,2,3,3,3,4,5,5,7,8,9,9}));

	return 0;

}

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

#include "../../utils/Assert.h"
#include "../../utils/PrintVector.h"

template <typename T>
void quickSort(
	std::vector<T>& sequence)
{

	typedef typename std::vector<T> Sequence;
	typedef typename Sequence::iterator Iterator;

	int size = sequence.size();

	// Check base case where sequence is trivially sorted

	if(size < 2)
	{
		return;
	}

	// 1. Divide: Divide the given sequence into two subsequences;

	Iterator pivot = --sequence.end();

	std::vector<T> L;
	std::vector<T> E;
	std::vector<T> G;

	// Divide sequence into L, E, and G subsequences

	while(!sequence.empty())
	{

		T element = sequence.back();

		sequence.pop_back();

		if(element < *pivot)
		{
			L.push_back(element);
		}
		else if(element > *pivot)
		{
			G.push_back(element);
		}
		else {
			E.push_back(element);
		}

	}

	// At this point 'pivot' position is invalidated;

	assert("All elements of S are accounted for in L, E, and G",
		L.size() + E.size() + G.size() == size);

	// 2. Recur: Sort each subsequence by calling quickSort();

	quickSort(L);
	quickSort(G);

	// 3. Conquer: Combine (concatenate) the two sorted results with the pivot;

	sequence.insert(sequence.end(), L.begin(), L.end());
	sequence.insert(sequence.end(), E.begin(), E.end());
	sequence.insert(sequence.end(), G.begin(), G.end());

	assert("All elements originally in S are given back.",
		sequence.size() == size);

}

#endif

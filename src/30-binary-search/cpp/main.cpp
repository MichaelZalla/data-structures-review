#include <vector>

#include "../../utils/cpp/Assert.h"
#include "../../utils/cpp/GetVector.h"

#include "./BinarySearch.h"

int main(int argc, char** argv)
{

	int sequence1[] = {};
	int sequence1Size = sizeof(sequence1)/sizeof(int);

	int sequence2[] = {2};
	int sequence2Size = sizeof(sequence2)/sizeof(int);

	int sequence3[] = {5,7,8};
	int sequence3Size = sizeof(sequence3)/sizeof(int);

	int sequence4[] = {0,0,0,0,0};
	int sequence4Size = sizeof(sequence4)/sizeof(int);

	// Binary search, base case: Empty sequence

	assert("1. Unsuccessful searches return an invalid index result.",
		binarySearch(sequence1, sequence1Size, 4) == -1);

	// Binary search, base case: 1-element sequence

	assert("2. Unsuccessful searches return an invalid index result.",
		binarySearch(sequence2, sequence2Size, 1) == -1);

	assert("3. Successful searches return the query's index the container.",
		binarySearch(sequence2, sequence2Size, 2) == 0);

	// Binary search, recursive case: 3-element sequence

	assert("4. Unsuccessful searches return an invalid index result.",
		binarySearch(sequence3, sequence3Size, 4) == -1);

	assert("5. Successful searches return the query's index the container.",
		binarySearch(sequence3, sequence3Size, 5) == 0);

	assert("6. Successful searches return the query's index the container.",
		binarySearch(sequence3, sequence3Size, 7) == 1);

	assert("7. Successful searches return the query's index the container.",
		binarySearch(sequence3, sequence3Size, 8) == 2);

	// Binary search, recursive case:

	assert("8. The middle value is return in the case of duplicate matches.",
		binarySearch(sequence4, sequence4Size, 0) == 2);

	return 0;

}

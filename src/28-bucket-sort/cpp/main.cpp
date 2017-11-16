#include <vector>

#include "../../utils/cpp/Assert.h"
#include "../../utils/cpp/PrintVector.h"

#include "./BucketSort.h"

int main(int argc, char** argv)
{

	int unsorted[] = { 5,5,1,2,4,5,1,4,2,4,2,3,1,2,4,5,1 };
	int sorted[] = { 1,1,1,1,2,2,2,2,3,4,4,4,4,5,5,5,5 };
	int n = sizeof(unsorted)/sizeof(int);

	std::vector<int> keys(unsorted, unsorted + n);

	bucketSort(keys);

	assert("Bucket sort", keys == std::vector<int>(sorted, sorted + n));

	return 0;

}

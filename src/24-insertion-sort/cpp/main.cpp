#include "../../utils/cpp/Assert.h"

#include "./InsertionSort.h"

int main(int argc, char** argv)
{

	int sorted[] = {0,1,2,3,4,5,6,7,8,9};

	int toBeSorted[] = {7,5,8,9,4,3,6,1,2,0};

	insertionSort(toBeSorted, 10);

	for(int i = 0; i < 10; i++)
	{
		assert("The 'toBeSorted' list is now sorted.",
			toBeSorted[i] == sorted[i]);
	}

	return 0;

}

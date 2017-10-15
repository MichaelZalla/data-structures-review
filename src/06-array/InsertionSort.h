template <typename T>
void insertionSort(T* L, int length)
{

	for(int sortedUpToIndex = 1; sortedUpToIndex < length; sortedUpToIndex++)
	{

		T valueBeingSorted = L[sortedUpToIndex];

		int indexToCompareAgainst = sortedUpToIndex - 1;

		while((indexToCompareAgainst > -1) && (L[indexToCompareAgainst] > valueBeingSorted))
		{
			L[indexToCompareAgainst + 1] = L[indexToCompareAgainst];

			indexToCompareAgainst--;
		}

		L[indexToCompareAgainst + 1] = valueBeingSorted;

	}

}

from math import floor

def binarySearch(sequence, query, leftIndex=0, rightIndex=None):

    if rightIndex == None:

        rightIndex = len(sequence) - 1

    # Base case: Query is not found

    if leftIndex > rightIndex:

        return -1

    midIndex = leftIndex + floor((rightIndex - leftIndex) / 2)

    # Base case: Query is found

    if sequence[midIndex] == query:

        return midIndex

    # Recursive case: Continue search in the left half

    elif sequence[midIndex] > query:

        return binarySearch(sequence, query, leftIndex, midIndex - 1)

    # Recursive case: Continue search in the right half

    else:

        return binarySearch(sequence, query, midIndex + 1, rightIndex)

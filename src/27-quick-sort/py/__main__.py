import sys

sys.path.append('../../utils/py')

from IsSorted import isSorted

from QuickSort import quickSort

# Test verification function

assert(isSorted([5,1,2,4,9,8,7,1,9]) == False)

assert(isSorted([1,1,2,4,5,7,8,9,9]) == True)

# Quick-sort, base case: Empty sequence

sequence = []

quickSort(sequence)

assert(isSorted(sequence))

# Quick-sort, base case: 1-element sequence

sequence = [7]

quickSort(sequence)

assert(isSorted(sequence))

# Quick-sort, simple recursive case: 3-element sequence

sequence = [8,13,5]

quickSort(sequence)

assert(isSorted(sequence))

# Quick-sort, larger recursive case: 20-element sequence

sequence = [7,58,9,71,2098,37,50,18263,1,5702,38975,9081,2,3480,97]

quickSort(sequence)

assert(isSorted(sequence))

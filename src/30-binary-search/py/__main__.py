from BinarySearch import binarySearch

# Binary search, base case: Empty sequence

assert(binarySearch([], 4) == -1)

# Binary search, base case: 1-element sequence

assert(binarySearch([2], 1) == -1)
assert(binarySearch([2], 2) == 0)

# Binary search, recursive case: 3-element sequence

assert(binarySearch([5,7,8], 4) == -1)
assert(binarySearch([5,7,8], 5) == 0)
assert(binarySearch([5,7,8], 7) == 1)
assert(binarySearch([5,7,8], 8) == 2)
assert(binarySearch([5,7,8], 9) == -1)

# Binary search, recursive case:

assert(binarySearch([0,0,0,0,0], 0) == 2)

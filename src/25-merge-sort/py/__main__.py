from Merge import merge

from MergeSort import merge_sort

# Tests for merge routine

assert(merge([], []) == [])

assert(merge([1], []) == [1])

assert(merge([], [1]) == [1])

assert(merge([1], [1]) == [1,1])

assert(merge([1,2], [3]) == [1,2,3])

assert(merge([3], [1,2]) == [1,2,3])

assert(merge([1,2,3,4,4,5,6,7,7,8,9], [1,1,5,5,5,5,5,6,6,9]) == [1,1,1,2,3,4,4,5,5,5,5,5,5,6,6,6,7,7,8,9,9])

# Tests for merge_sort routine

assert(merge_sort([]) == [])

assert(merge_sort([5]) == [5])

assert(merge_sort([5,1]) == [1,5])

assert(merge_sort([5,8,1,2,7,9,4,2,1,5,1]) == [1,1,1,2,2,4,5,5,7,8,9])

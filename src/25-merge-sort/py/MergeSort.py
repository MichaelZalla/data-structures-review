import math

from Merge import merge

def merge_sort(list, beginIndex=None, endIndex=None):

	if beginIndex == None:
		beginIndex = 0

	if endIndex == None:
		endIndex = len(list)

	size = endIndex - beginIndex

	# Base case (n < 2)

	if size <= 1:

		return list[beginIndex:endIndex]

	# Recursive case (n >= 2)

	else:

		#   B     M     E
		# [ 1, 2, 5, 7]   =>   [1, 2] [5, 7]

		midIndex = beginIndex + math.floor(size / 2)

		leftSorted = merge_sort(list, beginIndex, midIndex)

		rightSorted = merge_sort(list, midIndex, endIndex)

		return merge(leftSorted, rightSorted)

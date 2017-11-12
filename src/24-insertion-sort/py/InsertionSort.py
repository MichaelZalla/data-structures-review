def insertionSort(list):

	for i in range(1, len(list)):

		# Pull list[i] 'out' of the list, leaving a hole

		holeIndex = i

		# Store list[i] in a temporary variable

		value = list[i]

		# Swap the 'hole' to the left until list[holeIndex - 1] <= value

		while holeIndex > 0 and list[holeIndex - 1] > value:

			list[holeIndex] = list[holeIndex - 1]

			holeIndex -= 1

		list[holeIndex] = value

	return list

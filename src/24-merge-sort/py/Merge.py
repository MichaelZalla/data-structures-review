def merge(leftList, rightList):

	leftCursor = 0
	rightCursor = 0

	leftLen = len(leftList)
	rightLen = len(rightList)

	merged = list()

	while leftCursor < leftLen or rightCursor < rightLen:

		if leftCursor == leftLen:

			merged.append(rightList[rightCursor])

			rightCursor += 1

		elif rightCursor == rightLen:

			merged.append(leftList[leftCursor])

			leftCursor += 1

		elif leftList[leftCursor] <= rightList[rightCursor]:

			merged.append(leftList[leftCursor])

			leftCursor += 1

		else: # leftList[leftCursor] > rightList[rightCursor]:

			merged.append(rightList[rightCursor])

			rightCursor += 1

	return merged

def isSorted(sequence):

	if(len(sequence) < 2):
		return True

	for index, element in enumerate(sequence[0:-1]):
		if element > sequence[index+1]:
			return False

	return True

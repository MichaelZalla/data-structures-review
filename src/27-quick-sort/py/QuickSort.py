def quickSort(sequence):

	# Check base case where sequence is trivially sorted

	if len(sequence) < 2:
		return

	# 1. Divide: Divide the given sequence into two subsequences;

	pivot = sequence[-1]

	# Divide sequence into L, E, and G subsequences

	L = []
	E = []
	G = []

	while len(sequence) > 0:

		element = sequence[-1]

		sequence.pop()

		if element < pivot:
			L.append(element)

		elif element > pivot:
			G.append(element)

		else:
			E.append(element)

	# 2. Recur: Sort each subsequence by calling quickSort();

	quickSort(L)
	quickSort(G)

	# 3. Conquer: Combine (concatenate) the two sorted results with the pivot;

	sequence.extend(L)
	sequence.extend(E)
	sequence.extend(G)

	return sequence

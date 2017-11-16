#include "../utils/cpp/Assert.h"

#include "./List.h"

int main(int argc, char** argv)
{

	List<int> sequence;

	assert("The sequence is empty",
		sequence.isEmpty());

	assert("The sequence is empty",
		sequence.size() == 0);

	assert("The begin and end iterators are equal for an empty list",
		sequence.begin() == sequence.end());

	assert("The begin and end iterators initially point to sentinel values",
		*sequence.begin() == 0 && *sequence.end() == 0);

	assert("The list's begin() and end() methods return new iterators with each invocation.",
		sequence.begin() != ++sequence.begin() && sequence.end() != --sequence.end());

	sequence.insertBack(1);
	sequence.insertBack(1);
	sequence.insertBack(2);
	sequence.insertBack(3);
	sequence.insertBack(5);
	sequence.insertBack(8);

	assert("The sequence is no longer empty",
		sequence.isEmpty() == false);

	assert("The sequence now contains 6 elements",
		sequence.size() == 6);

	assert("The first position holds the value 1",
		*sequence.begin() == 1);

	assert("The last position holds the value 8",
		*(--sequence.end()) == 8);

	List<int>::Iterator positionA = sequence.begin();
	List<int>::Iterator positionB = sequence.begin();

	++positionA;
	++positionA;

	++positionB;
	++positionB;

	assert("Two iterators pointing to the same node are considered equal.",
		positionA == positionB &&
		*positionA == 2 &&
		*positionB == 2);

	return 0;

}

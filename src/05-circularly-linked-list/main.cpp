#include "../utils/cpp/Assert.h"
#include "./CircularlyLinkedList.h"

int main(int argv, char** args)
{

	CircularlyLinkedList<int>* L = new CircularlyLinkedList<int>;

	assert("The list is empty.", L->isEmpty() == true);

	L->add(6);

	assert("The list is no longer empty.", L->isEmpty() == false);

	assert("The cursor points to a node with value '6'.", L->front() == 6);

	assert("Front and back refer to the same node, with value '6'.", L->front() == L->back());

	L->add(44);

	assert("Front and back refer to different nodes.", L->front() != L->back());

	assert("Front holds the integer '44'.", L->front() == 44);

	assert("Back holds the integer '6'.", L->back() == 6);

	L->advance();

	assert("Front holds the integer '6'.", L->front() == 6);

	assert("Back holds the integer '44'.", L->back() == 44);

	L->advance();
	L->advance();

	assert("Front holds the integer '6'.", L->front() == 6);

	assert("Back holds the integer '44'.", L->back() == 44);

	while(!L->isEmpty())
	{
		L->remove();
	}

	assert("The list is now empty.", L->isEmpty() == true);

	return 0;

}

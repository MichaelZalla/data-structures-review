#include <iostream>
#include <stdexcept>

#include "../utils/Assert.h"
#include "./DoublyLinkedList.h"

int main(int argv, char** args)
{

	DoublyLinkedList<int>* L = new DoublyLinkedList<int>;

	assert("The list is empty.", L->isEmpty() == true);

	bool didThrow = false;

	try
	{
		L->front();
	}
	catch(std::runtime_error E)
	{
		didThrow = true;
	}

	assert("Was unable to call 'front()' on empty list structure.", didThrow);

	L->addFront(123);

	assert("The list is no longer empty.", L->isEmpty() == false);
	assert("The newly added node is at the front.", L->front() == 123);
	assert("Front and back refer to the same node.", L->front() == L->back());

	L->addFront(456);

	assert("Front and back refer to different nodes.", L->front() != L->back());
	assert("The newly added node is at the front.", L->front() == 456);
	assert("The first added node is now at the back.", L->back() == 123);

	L->addFront(111);
	L->addBack(444);
	L->addFront(222);
	L->addBack(999);

	assert("Front holds the integer '222'.", L->front() == 222);
	assert("Back holds the integer '999'.", L->back() == 999);

	L->removeFront();
	L->removeBack();

	assert("Front holds the integer '111'.", L->front() == 111);
	assert("Back holds the integer '444'.", L->back() == 444);

	while(!L->isEmpty())
	{
		L->removeFront();
	}

	assert("The list is empty.", L->isEmpty() == true);

	return 0;

}

#include <iostream>

#include "../utils/cpp/Assert.h"
#include "./SinglyLinkedList.h"

int main(int argv, char** args)
{

	SinglyLinkedList<int>* L = new SinglyLinkedList<int>;

	assert("The list is empty.", L->isEmpty() == true);

	L->addFront(3);

	assert("The list is no longer empty.", L->isEmpty() == false);
	assert("The front of the list holds the integer '3'.", L->front() == 3);

	L->addFront(2);
	L->addFront(1);
	L->addFront(0);

	assert("The front of the list holds the integer '0'.", L->front() == 0);

	while(!(L->isEmpty()))
	{
		L->removeFront();
	}

	assert("The list is now empty again.", L->isEmpty() == true);

	return 0;

}

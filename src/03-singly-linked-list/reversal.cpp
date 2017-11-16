#include <iostream>

#include "../utils/cpp/Assert.h"
#include "./SinglyLinkedList.h"

int main(int argv, char** args)
{

	SinglyLinkedList<int> L;

	L.addFront(3);
	L.addFront(2);
	L.addFront(1);
	L.addFront(0);

	L.print();

	L.reverse();

	L.print();

	L.reverse();
	L.reverse();
	L.reverse();
	L.reverse();

	L.print();

	return 0;

}

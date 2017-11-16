#include "../utils/cpp/Assert.h"
#include "../IndexOutOfBounds.h"

#include "./Vector.h"

int main(int argc, char** argv)
{

	Vector<int>* L = new Vector<int>(3);

	assert("The new list is empty.", L->isEmpty());

	assert("The new list size is zero.", L->size() == 0);

	bool didThrow = false;

	try
	{
		L[333] = 1;
	}
	catch(IndexOutOfBounds e)
	{
		didThrow = true;
	}

	assert("Indexing into an invalid index will not necessarily throw.", !didThrow);

	didThrow = false;

	try
	{
		L->at(333) = 1;
	}
	catch(IndexOutOfBounds e)
	{
		didThrow = true;
	}

	assert("Retrieveing an element using 'at()' with an invalid index will throw.", didThrow);

	L->reserve(5);

	assert("Reserving additional capcity does not affect list size.", L->size() == 0);

	L->insert(0, 1);
	L->insert(1, 2);
	L->insert(2, 3);

	assert("Insert operations modify the list's size.", L->size() == 3);

	L->insert(3, 8);
	L->insert(4, 9);
	L->insert(5, 0);

	assert("Inserting beyond the current capacity will expand the capacity.", L->size() == 6);

	L->erase(0);
	L->erase(0);
	L->erase(0);

	assert("Erase operations modify the list's size.", L->size() == 3);

	assert("Write operations can modify an element's rank in the list.",
		L->at(0) == 8 &&
		L->at(1) == 9 &&
		L->at(2) == 0);

	return 0;

}

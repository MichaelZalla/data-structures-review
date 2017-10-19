#include "../assert.h"

#include "./ArrayStack.h"
#include "./ListStack.h"

int main(int argc, char** argv)
{

	// Initialize our two interchangeable stack implementations

	ArrayStack<int>* arrayStack = new ArrayStack<int>;
	ListStack<int>* listStack = new ListStack<int>;

	// Assert that both implementations support the same interface

	assert("(ArrayStack) The stack's size is initially zero.", arrayStack->size() == 0);
	assert("(ListStack) The stack's size is initially zero.", listStack->size() == 0);

	assert("(ArrayStack) The stack is initially empty.", arrayStack->isEmpty() == true);
	assert("(ListStack) The stack is initially empty.", listStack->isEmpty() == true);

	//

	bool arrayDidThrow = false;

	bool listDidThrow = false;

	try
	{
		arrayStack->top();
	}
	catch(StackEmptyException e)
	{
		arrayDidThrow = true;
	}

	try
	{
		listStack->top();
	}
	catch(StackEmptyException e)
	{
		listDidThrow = true;
	}

	assert("(ArrayStack) Calling 'top()' on an empty stack generates an exception.", arrayDidThrow);

	assert("(ListStack) Calling 'top()' on an empty stack generates an exception.", listDidThrow);

	arrayDidThrow = false;

	listDidThrow = false;

	try
	{
		arrayStack->pop();
	}
	catch(StackEmptyException e)
	{
		arrayDidThrow = true;
	}

	try
	{
		listStack->pop();
	}
	catch(StackEmptyException e)
	{
		listDidThrow = true;
	}

	assert("(ArrayStack) Calling 'pop()' on an empty stack generates an exception.", arrayDidThrow);

	assert("(ListStack) Calling 'pop()' on an empty stack generates an exception.", listDidThrow);

	//

	arrayStack->push(45);
	listStack->push(45);

	assert("(ArrayStack) The stack's size is now 1.", arrayStack->size() == 1);
	assert("(ListStack) The stack's size is now 1.", listStack->size() == 1);

	assert("(ArrayStack) The stack is no longer empty.", arrayStack->isEmpty() == false);
	assert("(ListStack) The stack is no longer empty.", listStack->isEmpty() == false);

	assert("(ArrayStack) The stack's top now points to 45.", arrayStack->top() == 45);
	assert("(ListStack) The stack's top now points to 45.", listStack->top() == 45);

	//

	arrayStack->push(25);
	arrayStack->push(17);
	arrayStack->push(98);

	listStack->push(25);
	listStack->push(17);
	listStack->push(98);

	assert("(ArrayStack) The stack's size is now 4.", arrayStack->size() == 4);
	assert("(ListStack) The stack's size is now 4.", listStack->size() == 4);

	assert("(ArrayStack) The stack's top now points to 98.", arrayStack->top() == 98);
	assert("(ListStack) The stack's top now points to 98.", listStack->top() == 98);

	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();

	listStack->pop();
	listStack->pop();
	listStack->pop();
	listStack->pop();

	assert("(ArrayStack) The stack is now empty.", arrayStack->isEmpty() == true);
	assert("(ListStack) The stack is now empty.", listStack->isEmpty() == true);

	return 0;

}

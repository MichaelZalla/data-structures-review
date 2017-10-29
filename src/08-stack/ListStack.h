#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "../03-singly-linked-list/SinglyLinkedList.h"

#include "./StackException.h"

template <typename T>
class ListStack {

public:

	ListStack<T>() : list(), stackSize(0) {}

	int size() const
	{
		return this->stackSize;
	}

	bool isEmpty() const
	{
		return this->list.isEmpty();
	}

	const T& top() const throw(StackEmptyException)
	{

		if(this->isEmpty())
		{
			throw StackEmptyException("Called top() on empty stack!");
		}

		return this->list.front();
	}

	void push(const T& e)
	{

		this->list.addFront(e);

		this->stackSize++;

	}

	void pop() throw(StackEmptyException)
	{

		if(this->isEmpty())
		{
			throw StackEmptyException("Called pop() on empty stack!");
		}

		this->list.removeFront();

		this->stackSize--;

	}

private:

	SinglyLinkedList<T> list;

	int stackSize;

};

#endif

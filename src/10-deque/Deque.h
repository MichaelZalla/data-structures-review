#ifndef DEQUE_H
#define DEQUE_H

#include "../04-doubly-linked-list/DoublyLinkedList.h"
#include "./DequeException.h"

template <typename T>
class Deque {

public:

	Deque() : currentSize(0)
	{
		// Do nothing
	}

	int size()
	{
		return this->currentSize;
	}

	bool isEmpty()
	{
		return (this->currentSize == 0);
	}

	const T& front() const
	{
		return this->L.front();
	}

	const T& back() const
	{
		return this->L.back();
	}

	void insertFront(const T& elem)
	{
		this->L.addFront(elem);

		this->currentSize++;
	}

	void insertBack(const T& elem)
	{
		this->L.addBack(elem);

		this->currentSize++;
	}

	void removeFront()
	{
		if(this->isEmpty())
		{
			throw DequeEmptyException("Called removeFront() on empty deque!");
		}

		this->L.removeFront();

		this->currentSize--;
	}

	void removeBack()
	{
		if(this->isEmpty())
		{
			throw DequeEmptyException("Called removeBack() on empty deque!");
		}

		this->L.removeBack();

		this->currentSize--;
	}

private:

	int currentSize;

	DoublyLinkedList<T> L;

};

#endif

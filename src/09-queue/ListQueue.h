#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "../05-circularly-linked-list/CircularlyLinkedList.h"
#include "./QueueException.h"

template <typename T>
class ListQueue {

public:

	ListQueue() :
		currentSize(0),
		list(new CircularlyLinkedList<T>())
	{
		// Do nothing
	}

	int size() const
	{
		return this->currentSize;
	}

	bool isEmpty() const
	{
		return (this->currentSize == 0);
	}

	const T& front() const throw(QueueEmptyException)
	{

		if(this->isEmpty())
		{
			throw QueueEmptyException("Called front() on empty queue!");
		}

		return this->list->front();

	}

	void enqueue(const T& elem)
	{
		this->list->add(elem);

		this->list->advance();

		this->currentSize++;
	}

	void dequeue() throw(QueueEmptyException)
	{
		if(this->isEmpty())
		{
			throw QueueEmptyException("Called dequeue() on empty queue!");
		}

		this->list->remove();

		this->currentSize--;
	}

private:

	int currentSize;

	CircularlyLinkedList<T>* list;

};

#endif

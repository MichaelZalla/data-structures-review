#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "./QueueException.h"

template <typename T>
class ArrayQueue {

public:

	ArrayQueue(const int capacity = 0) :
		capacity(capacity),
		queue(new T[capacity]),
		currentSize(0),
		frontIndex(0),
		rearIndex(0)
	{
		// Do nothing?
	}

	~ArrayQueue()
	{
		delete[] this->queue;
	}

	const int size()
	{

		return this->currentSize;

	}

	const bool isEmpty()
	{

		return (this->currentSize == 0);

	}

	const T& front() throw(QueueEmptyException)
	{

		if(this->isEmpty())
		{
			throw QueueEmptyException("Called front() on empty qeueue!");
		}

		return this->queue[this->frontIndex];

	}

	void enqueue(const T& elem) throw(QueueFullException)
	{

		if(this->currentSize == this->capacity)
		{
			throw QueueFullException("Called enqueue() on full queue!");
		}

		this->queue[this->rearIndex] = elem;

		this->rearIndex = (this->rearIndex + 1) % this->capacity;

		this->currentSize++;

	}

	void dequeue() throw(QueueEmptyException)
	{

		if(this->isEmpty())
		{
			throw QueueEmptyException("Called dequeue() on empty queue!");
		}

		this->frontIndex = (this->frontIndex + 1) % this->capacity;

		this->currentSize--;

	}

private:

	int capacity;
	int currentSize;

	T* queue;

	int frontIndex;
	int rearIndex;

};

#endif

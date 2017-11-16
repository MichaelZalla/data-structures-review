#ifndef CIRCULARLY_LINKED_LIST_H
#define CIRCULARLY_LINKED_LIST_H

#include <stdexcept>

#include "../utils/cpp/Assert.h"
#include "./CircularlyLinkedNode.h"

template <typename T>
class CircularlyLinkedList {

public:

	CircularlyLinkedList()
	{
		this->cursor = 0;
	}

	~CircularlyLinkedList()
	{
		while(!this->isEmpty())
		{
			this->remove();
		}
		delete this->cursor;
	}

	bool isEmpty() const
	{
		return (this->cursor == 0);
	}

	const T& front() const throw(std::runtime_error)
	{
		this->assertNotEmpty();

		return this->cursor->next->elem;
	}

	const T& back() const throw(std::runtime_error)
	{
		this->assertNotEmpty();

		return this->cursor->elem;
	}

	// @NOTE(mzalla) Too harsh to throw exception on empty advance call?

	void advance() throw(std::runtime_error)
	{
		this->assertNotEmpty();

		this->cursor = this->cursor->next;
	}

	void add(const T& elem)
	{
		CircularlyLinkedNode<T>* node = new CircularlyLinkedNode<T>;

		node->elem = elem;

		if(this->isEmpty())
		{
			this->cursor = node;
			this->cursor->next = this->cursor;
		}
		else
		{
			node->next = this->cursor->next;

			this->cursor->next = node;
		}

	}

	void remove() throw(std::runtime_error)
	{
		this->assertNotEmpty();

		CircularlyLinkedNode<T>* node = this->cursor->next;

		if(node == this->cursor)
		{
			this->cursor = 0;
		}
		else
		{
			this->cursor->next = node->next;
		}

		delete node;
	}

private:

	CircularlyLinkedNode<T>* cursor;

protected:

	void assertNotEmpty() const throw(std::runtime_error)
	{

		if(this->isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

	}

};

#endif

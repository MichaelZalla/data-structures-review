#include <stdexcept>

#include "../assert.h"
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

	bool isEmpty()
	{
		return (this->cursor == 0);
	}

	const T& front()
	{
		this->assertNotEmpty();

		return this->cursor->next->elem;
	}

	const T& back()
	{
		this->assertNotEmpty();

		return this->cursor->elem;
	}

	// @NOTE(mzalla) Too harsh to throw exception on empty advance call?

	void advance()
	{
		this->assertNotEmpty();

		this->cursor = this->cursor->next();
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

	void remove()
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

	void assertNotEmpty()
	{

		if(this->isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

	}

};

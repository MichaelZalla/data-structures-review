#include <stdexcept>

#include "../assert.h"
#include "./DoublyLinkedNode.h"

template <typename T>
class DoublyLinkedList {

public:

	DoublyLinkedList<T>()
	{

		// Initialize sentinel nodes

		this->head = new DoublyLinkedNode<T>;
		this->tail = new DoublyLinkedNode<T>;

		// @NOTE(mzalla) Initialize this->tail before assigning next/prev
		// pointers!

		this->head->next = tail;
		this->tail->prev = head;

	}

	~DoublyLinkedList<T>()
	{

		// Flush out all list entries

		while(!this->isEmpty())
		{
			this->removeFront();
		}

		// Dealloac sentinel nodes

		delete this->head;
		delete this->tail;

	}

	const bool isEmpty()
	{
		return (this->head->next == this->tail);
	}

	const T& front()
	{
		this->assertNotEmpty();

		return this->head->next->elem;
	}

	const T& back()
	{
		this->assertNotEmpty();

		return this->tail->prev->elem;
	}

	void addFront(const T& elem)
	{
		this->add(elem, this->head);
	}

	void addBack(const T& elem)
	{
		this->add(elem, this->tail->prev);
	}

	void removeFront()
	{
		this->remove(this->head->next);
	}

	void removeBack()
	{
		this->remove(this->tail->prev);
	}

private:

	DoublyLinkedNode<T>* head;

	DoublyLinkedNode<T>* tail;

protected:

	void add(
		const T& elem,
		DoublyLinkedNode<T>* before)
	{

		// @NOTE(mzalla) No need for special handling of 'empty' scenario;

		DoublyLinkedNode<T>* node = new DoublyLinkedNode<T>;

		node->elem = elem;

		node->prev = before;
		node->next = before->next;

		before->next->prev = node;
		before->next = node;

	}

	void remove(
		DoublyLinkedNode<T>* node)
	{

		this->assertNotEmpty();

		node->prev->next = node->next;

		node->next->prev = node->prev;

		delete node;

	}

	void assertNotEmpty()
	{

		if(this->isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

	}

};

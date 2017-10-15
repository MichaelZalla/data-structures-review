#include <stdexcept>

#include "./SinglyLinkedNode.h"

template <typename T>
class SinglyLinkedList {

public:

	SinglyLinkedList()
	{
		this->head = 0;
	}

	~SinglyLinkedList()
	{

		while(!this->isEmpty())
		{
			this->removeFront();
		}

		delete this->head;

	}

	const bool isEmpty()
	{
		return (this->head == 0);
	}

	const T& front()
	{

		if(this->isEmpty())
		{
			throw std::runtime_error("No elements to return!");
		}

		return this->head->elem;

	}

	void addFront(const T& elem)
	{

		SinglyLinkedNode<T>* node = new SinglyLinkedNode<T>;

		if(this->isEmpty())
		{
			node->next = 0;
		}
		else
		{
			node->next = this->head;
		}

		node->elem = elem;

		this->head = node;

	}

	void removeFront()
	{

		const SinglyLinkedNode<T>* node = this->head;

		if(node == 0)
		{
			throw std::runtime_error("No elements to remove!");
		}

		this->head = this->head->next;

		delete node;

	}

private:

	SinglyLinkedNode<T>* head;

};

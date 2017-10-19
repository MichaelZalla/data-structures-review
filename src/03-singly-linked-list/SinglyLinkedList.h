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

	bool isEmpty() const
	{
		return (this->head == 0);
	}

	const T& front() const throw(std::runtime_error)
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

	void removeFront() throw(std::runtime_error)
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

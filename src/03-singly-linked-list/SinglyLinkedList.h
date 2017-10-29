#include <iostream>
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

	void print() const
	{

		std::cout << "SinglyLinkedList { ";

		SinglyLinkedNode<T>* node = this->head;

		while(node != 0)
		{
			std::cout << node->elem;

			if(node->next != 0)
			{
				std::cout << ", ";
			}

			node = node->next;

		}

		std::cout << "}" << std::endl;

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

	void reverse()
	{

		if(this->isEmpty())
		{
			return;
		}

		SinglyLinkedNode<T>* currentNode = this->head;
		SinglyLinkedNode<T>* previousNode = 0;
		SinglyLinkedNode<T>* nextNode = currentNode->next;

		while(nextNode != 0)
		{

			// Redirect the current node's 'next' pointer to the preceeding node
			// (or to null);
			currentNode->next = previousNode;

			previousNode = currentNode;

			// Advance to the next node;
			currentNode = nextNode;

			// Advance our 'next' pointer to the following node (or to null);
			nextNode = nextNode->next;

		}

		currentNode->next = previousNode;

		this->head = currentNode;

	}

private:

	SinglyLinkedNode<T>* head;

};

#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{

private:

	struct Node
	{
		T elem;
		Node* prev;
		Node* next;
	};

public:

	class Iterator
	{

	public:

		Iterator(Node* node)
		{
			this->node = node;
		}

		const T& operator*()
		{
			return this->node->elem;
		}

		bool operator==(const Iterator& position) const
		{
			return (this->node == position.node);
		}

		bool operator!=(const Iterator& position) const
		{
			return (this->node != position.node);
		}

		Iterator& operator++()
		{
			// Note that we return a reference to the Iterator that was called;

			this->node = this->node->next;

			return (*this);
		}

		Iterator& operator--()
		{
			// Note that we return a reference to the Iterator that was called;

			this->node = this->node->prev;

			return (*this);
		}

		friend class List;

	private:

		Node* node;

	};

public:

	List<T>()
	{

		this->headNode = new Node;
		this->tailNode = new Node;

		this->headNode->next = this->tailNode;
		this->tailNode->prev = this->headNode;

		this->currentSize = 0;

	}

	int size() const
	{
		return this->currentSize;
	}

	bool isEmpty() const
	{
		return (this->currentSize == 0);
	}

	Iterator begin() const
	{
		return Iterator(this->headNode->next);
	}

	Iterator end() const
	{
		return Iterator(this->tailNode);
	}

	void insertFront(const T& elem)
	{
		this->insert(this->begin(), elem);
	}

	void insertBack(const T& elem)
	{
		this->insert(this->end(), elem);
	}

	void insert(const Iterator& position, const T& elem)
	{
		// Note that we insert a new node *before* `position`...

		// Allocate the new node

		Node* nextNode = position.node;

		Node* prevNode = position.node->prev;

		Node* newNode = new Node;

		newNode->elem = elem;

		// Link the new node to the node that follows it

		newNode->next = nextNode;

		nextNode->prev = newNode;

		// Link the new node to the node that preceeds it

		newNode->prev = prevNode;

		prevNode->next = newNode;

		// Increment our list's size

		this->currentSize++;

	}

	void eraseFront()
	{
		this->erase(this->begin());
	}

	void eraseBack()
	{
		this->erase(--this->end());
	}

	void erase(const Iterator& position)
	{
		// Relink the surrounding nodes

		Node* removedNode = position.node;

		removedNode->prev->next = removedNode->next;

		removedNode->next->prev = removedNode->prev;

		// Decrement our list's size

		this->currentSize--;
	}

private:

	int currentSize;

	Node* headNode;
	Node* tailNode;

};

#endif

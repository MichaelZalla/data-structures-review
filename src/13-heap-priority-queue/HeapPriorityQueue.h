#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include "../12-complete-binary-tree/VectorCompleteBinaryTree.h"
#include "./PriorityQueueException.h"

template <typename T, typename C>
class HeapPriorityQueue {

private:

	typedef typename VectorCompleteBinaryTree<T>::Position Position;

public:

	int size() const
	{
		return this->tree.size();
	}

	int isEmpty() const
	{
		return (this->tree.size() == 0);
	}

	void print()
	{
		this->tree.print();
	}

	void insert(
		const T& element)
	{
		this->tree.addLast(element);

		Position root = this->tree.root();
		Position last = this->tree.last();

		this->restoreMinHeapPropertyUp(root, last);
	}

	const T& min() throw(PriorityQueueEmptyException)
	{
		if(this->isEmpty())
		{
			throw PriorityQueueEmptyException("Called min() on empty priority queue!");
		}

		return *this->tree.root();
	}

	void removeMin() throw(PriorityQueueEmptyException)
	{
		if(this->isEmpty())
		{
			throw PriorityQueueEmptyException("Called min() on empty priority queue!");
		}

		Position root = this->tree.root();
		Position last = this->tree.last();

		this->tree.swap(last, root);

		this->tree.removeLast();

		restoreMinHeapPropertyDown(root);

	}

private:

	VectorCompleteBinaryTree<T> tree;

	C isLessThan;

	void restoreMinHeapPropertyUp(
		Position& root,
		Position& position)
	{

		Position parent;

		while(position != root)
		{
			parent = this->tree.parent(position);

			if(!this->isLessThan(*position, *parent))
			{
				break;
			}

			this->tree.swap(position, parent);

			position = parent;
		}

	}

	void restoreMinHeapPropertyDown(
		Position& position)
	{

		while(this->tree.hasLeftChild(position)/* || this->tree.hasRightChild(position)*/)
		{

			Position child = this->tree.leftChild(position);

			if(this->tree.hasRightChild(position) &&
				isLessThan(
					*this->tree.rightChild(position),
					*child
				)
			)
			{
				child = this->tree.rightChild(position);
			}

			if(!this->isLessThan(*child, *position))
			{
				break;
			}

			this->tree.swap(child, position);

			position = child;

		}

	}

};

#endif

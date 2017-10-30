#ifndef VECTOR_COMPLETE_BINARY_TREE_H
#define VECTOR_COMPLETE_BINARY_TREE_H

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class VectorCompleteBinaryTree {

public:

	typedef typename std::vector<T>::iterator Position;

public:

	VectorCompleteBinaryTree() : vector(1)
	{
		// Initialize vector with a single placeholder position (index zero);
	}

	int size() const
	{
		// Ignores zero-index placeholder position

		return this->vector.size() - 1;
	}

	void print() {

		this->print(this->root());

	}

	Position leftChild(
		const Position& position)
	{
		return this->getPosition(this->getIndex(position) * 2);
	}

	Position rightChild(
		const Position& position)
	{
		return this->getPosition(this->getIndex(position) * 2 + 1);
	}

	Position parent(
		const Position& position)
	{
		return this->getPosition(this->getIndex(position) / 2);
	}

	bool hasLeftChild(
		const Position& position) const
	{
		int index = this->getIndex(position);

		return (index * 2 <= this->size());
	}

	bool hasRightChild(
		const Position& position) const
	{
		int index = this->getIndex(position);

		return (index * 2 + 1 <= this->size());
	}

	bool isRoot(
		const Position& position) const
	{
		return (this->getIndex(position) == 1);
	}

	Position root()
	{
		return this->getPosition(1);
	}

	Position last()
	{
		return this->getPosition(this->size());
	}

	void addLast(
		const T& elem)
	{
		this->vector.push_back(elem);
	}

	void removeLast()
	{
		this->vector.pop_back();
	}

	void swap(
		const Position& a,
		const Position& b)
	{
		// Swap the elements at positions a and b

		T temp = *a;
		a = *b;
		b = temp;
	}

protected:

	int getIndex(
		const Position& position) const
	{
		// Use iterator's '-' operator to calculate distance between indices;
		return (position - this->vector.begin());
	}

	Position getPosition(
		int index)
	{
		// We'll use index=1 when requesting a position for the root note;
		// hence, there is no need to return index+1 in this implementation;
		return (this->vector.begin() + index);
	}

private:

	std::vector<T> vector;

	void print(
		const Position& position,
		int depth = 0)
	{

		if(this->size() == 0)
		{
			return;
		}

		if(depth == 0)
		{
			std::cout << std::endl;
		}

		if(this->hasRightChild(position)) {
			this->print(this->rightChild(position), depth + 1);
		}

		std::cout << std::string(depth, '\t') << *position << std::endl;

		if(this->hasLeftChild(position)) {
			this->print(this->leftChild(position), depth + 1);
		}

		if(depth == 0)
		{
			std::cout << std::endl;
		}

	}

};

#endif

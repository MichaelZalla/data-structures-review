#include "../assert.h"
#include "../IndexOutOfBounds.h"

template <typename T>
class Vector {

public:

	Vector(int size = 0)
	{

		this->capacity = 0;
		this->currentSize = 0;
		this->collection = 0;

		if(size != 0)
		{
			this->reserve(size);
		}

	}

	~Vector()
	{
		if(this->collection != 0)
		{

			// @TODO(mzalla) Check whether this step is actually necessary...
			while(!this->isEmpty())
			{
				this->erase(this->currentSize - 1);
			}

			delete[] this->collection;

		}
	}

	int size() const
	{
		return this->currentSize;
	}

	bool isEmpty() const
	{
		return (this->currentSize == 0);
	}

	T& operator[](
		int index) const
	{
		return this->collection[index];
	}

	T& at(
		int index) const throw(IndexOutOfBounds)
	{
		this->assertSafeIndex(index);

		return this->collection[index];
	}

	void erase(
		int index)
	{

		// Guarantee capacity
		this->assertSafeIndex(index);

		// @TODO(mzalla) Shouldn't we dealloc the removed element to avoid
		// memory leaks?

		// Shift higher-rank elements toward the front
		for(int c = index + 1; c < this->currentSize; c++)
		{
			this->collection[c-1] = this->collection[c];
		}

		// Resize the collection
		this->currentSize--;

	}

	void insert(
		int index,
		const T& elem)
	{

		// Guarantee capacity
		this->reserve(index + 1);

		// Shift higher-rank elements toward the back
		for(int c = this->currentSize - 2; c >= index; c--)
		{
			this->collection[c+1] = this->collection[c];
		}

		// Insert the new element
		this->collection[index] = elem;

		// Resize the collection
		this->currentSize++;

	}

	void reserve(
		int capacity)
	{

		if(capacity <= this->capacity)
		{
			return;
		}

		T* newCollection = new T[capacity];

		// Copy over values
		for(int index = 0; index < this->currentSize; index++)
		{
			newCollection[index] = /*this[i]*/this->collection[index];
		}

		// Deallocate the original collection if necessary
		if(this->collection != 0)
		{
			delete[] this->collection;
		}

		// Update our collection reference
		this->collection = newCollection;

	}

private:

	int capacity;

	int currentSize;

	T* collection;

	void assertSafeIndex(
		const int index) const throw(IndexOutOfBounds)
	{

		if(index < 0 || index >= this->currentSize)
		{
			throw IndexOutOfBounds("");
		}

		return;

	}

};
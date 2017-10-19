#include "./StackException.h"

template <typename T>
class ArrayStack {

public:

	// @NOTE(mzalla) We could lazily initialize on the first push operation?

	ArrayStack<T>(int capacity = DEFAULT_STACK_CAPACITY)
		: capacity(capacity), A(new T[this->capacity]), topIndex(-1) {}

	~ArrayStack<T>()
	{

		while(!this->isEmpty())
		{
			this->pop();
		}

		delete[] this->A;

	}

	int size() const
	{
		return (this->topIndex + 1);
	}

	bool isEmpty() const
	{
		return (this->size() == 0);
	}

	const T& top() const throw(StackEmptyException)
	{

		if(this->isEmpty())
		{
			throw StackEmptyException("Called top() on empty stack!");
		}

		return this->A[this->topIndex];

	}

	void push(const T& e) throw(StackFullException)
	{
		if(this->size() >= this->capacity)
		{
			throw StackFullException("Called push() on full stack!");
		}

		this->A[++this->topIndex] = e;

	}

	void pop() throw(StackEmptyException)
	{

		if(this->isEmpty())
		{
			throw StackEmptyException("Called pop() on empty stack!");
		}

		// @NOTE(mzalla) No need to explicitly dealloc entry in array—T may be a
		// primitive, so the delete operator would not be appropriate; since we
		// are allocating a statically-sized array, any leftover (unused)
		// entries will eventually be dealloc'd when the entire array is deleted
		// by the class destructor method;
		//
		// delete this->A[this->topIndex--];
		//

		this->topIndex--;

	}

private:

	enum {
		DEFAULT_STACK_CAPACITY = 100
	};

	int capacity;

	int topIndex;

	T* A;

};

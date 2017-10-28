#include "../assert.h"
#include "../07-vector/Vector.h"

#include "./ArrayStack.h"

template <typename T>
void reverse(
	Vector<T>& collection)
{

	ArrayStack<T> stack(collection.size());

	while(!collection.isEmpty())
	{
		T value = collection.at(0);

		stack.push(value);

		collection.erase(0);
	}

	while(!stack.isEmpty())
	{
		T value = stack.top();

		collection.insert(collection.size(), value);

		stack.pop();
	}

}

int main(
	int argc,
	char** argv)
{

	Vector<int> numbers;

	numbers.insert(numbers.size(), 0);
	numbers.insert(numbers.size(), 1);
	numbers.insert(numbers.size(), 2);
	numbers.insert(numbers.size(), 3);
	numbers.insert(numbers.size(), 4);
	numbers.insert(numbers.size(), 5);

	numbers.print();

	reverse(numbers);

	numbers.print();

	return 0;

}

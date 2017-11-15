#include "../utils/Assert.h"
#include "./Deque.h"

int main(int argc, char** argv)
{

	Deque<int> deque;

	assert("The deque is initially empty.", deque.isEmpty() == true);
	assert("The deque has size zero.", deque.size() == 0);

	deque.insertBack(2);

	assert("The deque is not longer empty.", deque.isEmpty() == false);
	assert("The deque has size of 1.", deque.size() == 1);
	assert("The front element is 2.", deque.front() == 2);
	assert("The back element is 2.", deque.back() == 2);

	deque.insertBack(4);
	deque.insertBack(8);
	deque.insertBack(16);
	deque.insertBack(32);

	assert("The deque has size of 5.", deque.size() == 5);
	assert("The front element is 2.", deque.front() == 2);
	assert("The back element is 32.", deque.back() == 32);

	deque.insertFront(1);
	deque.insertFront(0);

	assert("The deque has size of 7.", deque.size() == 7);
	assert("The front element is 0.", deque.front() == 0);
	assert("The back element is 32.", deque.back() == 32);

	deque.removeFront();

	assert("The deque has size of 6.", deque.size() == 6);
	assert("The front element is 1.", deque.front() == 1);
	assert("The back element is 32.", deque.back() == 32);

	deque.removeBack();

	assert("The deque has size of 5.", deque.size() == 5);
	assert("The front element is 1.", deque.front() == 1);
	assert("The back element is 16.", deque.back() == 16);

	return 0;

}

#include "../assert.h"

#include "./ArrayQueue.h"
#include "./ListQueue.h"

int main(int argc, char** argv)
{

	// Initialize our two interchangeable queue implementations

	ArrayQueue<int> arrayQueue(5);
	ListQueue<int> listQueue;

	// Assert that both implementations support the same interface

	assert("(ArrayQueue) The queue's size is initially zero.", arrayQueue.size() == 0);
	assert("(ListQueue) The queue's size is initially zero.", listQueue.size() == 0);

	assert("(ArrayQueue) The queue is initially empty.", arrayQueue.isEmpty() == true);
	assert("(ListQueue) The queue is initially empty.", listQueue.isEmpty() == true);

	arrayQueue.enqueue(100);
	listQueue.enqueue(100);

	assert("(ArrayQueue) The front of the queue holds the value 100", arrayQueue.front() == 100);
	assert("(ListQueue) The front of the queue holds the value 100", listQueue.front() == 100);

	arrayQueue.dequeue();
	listQueue.dequeue();

	assert("(ArrayQueue) The queue is empty again.", arrayQueue.size() == 0);
	assert("(ArrayQueue) The queue is empty again.", arrayQueue.isEmpty() == true);
	assert("(ListQueue) The queue is empty again.", listQueue.size() == 0);
	assert("(ListQueue) The queue is empty again.", listQueue.isEmpty() == true);

	arrayQueue.enqueue(100);
	arrayQueue.enqueue(200);
	arrayQueue.enqueue(300);
	arrayQueue.enqueue(400);
	arrayQueue.enqueue(500);

	listQueue.enqueue(100);
	listQueue.enqueue(200);
	listQueue.enqueue(300);
	listQueue.enqueue(400);
	listQueue.enqueue(500);

	assert("(ArrayQueue) The queue's size is now 5.", arrayQueue.size() == 5);
	assert("(ArrayQueue) The front of the queue still holds the value 100", arrayQueue.front() == 100);
	assert("(ListQueue) The queue's size is now 5.", listQueue.size() == 5);
	assert("(ListQueue) The front of the queue still holds the value 100", listQueue.front() == 100);

	arrayQueue.dequeue();
	listQueue.dequeue();

	assert("(ArrayQueue) The queue's size is now 4.", arrayQueue.size() == 4);
	assert("(ArrayQueue) The front of the queue now holds the value 200", arrayQueue.front() == 200);
	assert("(ListQueue) The queue's size is now 4.", listQueue.size() == 4);
	assert("(ListQueue) The front of the queue now holds the value 200", listQueue.front() == 200);

	arrayQueue.dequeue();
	arrayQueue.dequeue();
	arrayQueue.dequeue();

	listQueue.dequeue();
	listQueue.dequeue();
	listQueue.dequeue();

	assert("(ArrayQueue) The queue's size is now 1.", arrayQueue.size() == 1);
	assert("(ArrayQueue) The front of the queue now holds the value 500", arrayQueue.front() == 500);
	assert("(ListQueue) The queue's size is now 1.", listQueue.size() == 1);
	assert("(ListQueue) The front of the queue now holds the value 500", listQueue.front() == 500);

	arrayQueue.dequeue();
	listQueue.dequeue();

	assert("(ArrayQueue) The queue is empty again.", arrayQueue.size() == 0);
	assert("(ArrayQueue) The queue is empty again.", arrayQueue.isEmpty() == true);
	assert("(ListQueue) The queue is empty again.", listQueue.size() == 0);
	assert("(ListQueue) The queue is empty again.", listQueue.isEmpty() == true);

	return 0;

}

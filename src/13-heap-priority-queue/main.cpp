#include "../12-complete-binary-tree/VectorCompleteBinaryTree.h"

#include "./HeapPriorityQueue.h"
#include "./IntegerComparator.h"

int main(int argc, char** argv)
{

	HeapPriorityQueue<int, IntegerComparator> hpq;

	hpq.print();

	hpq.insert(5);

	hpq.print();

	hpq.insert(24);
	hpq.insert(1);
	hpq.insert(195);

	hpq.print();

	hpq.insert(15451290);
	hpq.insert(2411);
	hpq.insert(-51);
	hpq.insert(3);

	hpq.print();

}

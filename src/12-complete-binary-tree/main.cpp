#include "./VectorCompleteBinaryTree.h"

int main(int argsc, char** argv)
{

	VectorCompleteBinaryTree<int> cbt;

	cbt.addLast(1);
	cbt.addLast(2);
	cbt.addLast(4);
	cbt.addLast(6);
	cbt.addLast(241);
	cbt.addLast(27);
	cbt.addLast(15);
	cbt.addLast(9105);

	cbt.print(cbt.root());

	cbt.removeLast();
	cbt.removeLast();

	cbt.print(cbt.root());

	cbt.removeLast();
	cbt.removeLast();
	cbt.removeLast();

	cbt.print(cbt.root());

	return 0;

}

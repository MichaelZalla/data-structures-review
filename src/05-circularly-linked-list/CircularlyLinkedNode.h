#ifndef CIRCULARLY_LINKED_NODE
#define CIRCULARLY_LINKED_NODE

template <typename T>
struct CircularlyLinkedNode {
	CircularlyLinkedNode* next;
	T elem;
};

#endif

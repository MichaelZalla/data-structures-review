#ifndef DOUBLY_LINKED_NODE_H
#define DOUBLY_LINKED_NODE_H

template <typename T>
struct DoublyLinkedNode {
	DoublyLinkedNode<T>* prev;
	DoublyLinkedNode<T>* next;
	T elem;
};

#endif

template <typename T>
struct DoublyLinkedNode {
	DoublyLinkedNode<T>* prev;
	DoublyLinkedNode<T>* next;
	T elem;
};

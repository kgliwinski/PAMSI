#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include "LinkedList.hh"

template<typename type>
LinkedList<type>::LinkedList() : head(nullptr)
{
}

template<typename type>
LinkedList<type>::~LinkedList()
{
}

template<typename type>
bool LinkedList<type>::isEmpty() const
{
	return this->head == nullptr;
}

template<typename type>
const type &LinkedList<type>::front() const
{
	return head->elem;
}

template<typename type>
void LinkedList<type>::addFront(const type &elem)
{
	ListNode<type> *newHead = new ListNode<type>; // create a new Node
	newHead->elem = elem;													// assign head elem value to v
	newHead->next = head;													// set head as next in list
	head = newHead;																// assign head to v
}

template<typename type>
void LinkedList<type>::removeFront()
{
	ListNode<type> *old = head; // assign old to head
	head = old->next;						// assign old head values to head
	delete old;									// delete old head
}

template<typename type>
unsigned int LinkedList<type>::size() const
{
	ListNode<type>* temp = head;
	unsigned int size = 0;

	while (temp != nullptr)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

#endif
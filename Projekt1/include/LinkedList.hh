#ifndef LINKED_LIST_HH
#define LINKED_LIST_HH
#include "ListNode.hh"

template<typename type>
class LinkedList
{
	private:
	ListNode<type> *head;

	public:
	LinkedList();
	~LinkedList();
	bool empty() const;
	const type &front() const;
	void addFront(const type &elem);
	void removeFront();
};

#include "../source/LinkedList.cpp"
#endif
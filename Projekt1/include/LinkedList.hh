#ifndef LINKED_LIST_HH
#define LINKED_LIST_HH
#include "ListNode.hh"

/*! \class LinkedList
	\brief Defines a LinkedList template class
*/
template<typename type>
class LinkedList
{
	private:
	ListNode<type> *head;

	public:
	/// \brief LinkedList constructor
	LinkedList();
	~LinkedList();

	/// \brief checks if LinkedList is empty
	bool isEmpty() const;

	/// \brief shows, but does not remove, a front element on the LinkedList
	const type &front() const;

	/// \brief adds an element on front of the LinkedList
	void addFront(const type &elem);

	/// \brief removes the front elem of the LinkedList
	void removeFront();

	/// \brief returns the size of LinkedList
	unsigned int size() const;
};

#include "../source/LinkedList.cpp"
#endif
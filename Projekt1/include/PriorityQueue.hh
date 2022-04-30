#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include "LinkedList.hh"
/*! \class PriorityQueue
 *  \brief Defines a Priority Queue template class
 */
template<typename type>
class PriorityQueue
{
	private:
	/// \brief Priority queue contents
	struct Node
	{
		type data;
		unsigned int key = { 0 };
		Node *next;
	};
    Node *head;

	public:
	/// \brief Default constructor
	PriorityQueue();

	/// \brief Number of elements in queue
	unsigned int size() const;

	/// \brief Checks if queue is empty
	bool isEmpty() const;

	/// \brief Insert element to queue
	void insert(const type &elem, const unsigned int &key);

	/// \brief Return minimum element
	const type &min() const;

	/// \brief Remove minimum element from queue
	void removeMin();
};

#include "../source/PriorityQueue.cpp"
#endif
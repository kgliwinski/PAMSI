#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include <iostream>

#include "LinkedList.hh"
#include "PriorityQueueNode.hh"
/*! \class PriorityQueue
 *  \brief Defines a Priority Queue template class
 */
template<typename type>
class PriorityQueue
{
	private:
	/// \brief PriorityQueue nodes
	PriorityQueueNode<type> *head;

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

    template<typename Ctype>
	friend std::ostream &operator<<(std::ostream &out, const PriorityQueue<Ctype> &queue);
};

/// \brief Ostream operator overload for PriorityQueue
template<typename type>
std::ostream &operator<<(std::ostream &out, const PriorityQueue<type> &queue);
#include "../source/PriorityQueue.cpp"
#endif
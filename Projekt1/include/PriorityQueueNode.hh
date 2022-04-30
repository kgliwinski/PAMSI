#ifndef PRIORITY_QUEUE_NODE_HH
#define PRIORITY_QUEUE_NODE_HH

/*! \class QueueNode
 *  \brief Contains definition of Priority Queue Node
 */
template<typename type>
class PriorityQueueNode
{
	private:
	type data;
	unsigned int key = { 0 };
	PriorityQueueNode *next;

	public:
    /// \brief Return key of a node element
    unsigned int getKey()
	{
		return this->key;
	}

	/// \brief Return data of a node element
	type getData()
	{
		return this->data;
	}

	/// \brief Return pointer to next element
	PriorityQueueNode *getNext()
	{
		return this->next;
	}

	template<typename Ctype> friend class PriorityQueue;
};

#endif
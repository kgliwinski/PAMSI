#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP
#include "../include/PriorityQueue.hh"

template<typename type>
PriorityQueue<type>::PriorityQueue() : head(nullptr)
{
}

template<typename type>
unsigned int PriorityQueue<type>::size() const
{
	PriorityQueueNode<type> *temp = head;
	unsigned int size = 0;

	while (temp != nullptr)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

template<typename type>
bool PriorityQueue<type>::isEmpty() const
{
	if (head != nullptr)
		return false;
	return true;
}

template<typename type>
void PriorityQueue<type>::insert(const type &elem, const unsigned int &key)
{
	try
	{
		PriorityQueueNode<type> *temp = head;
		PriorityQueueNode<type> *newElem = new PriorityQueueNode<type>;
		newElem->data = elem;
		newElem->next = nullptr;
		newElem->key = key;

		if (head == nullptr)
		{
			head = newElem;
		}
		else if (head->key > key)
		{
			newElem->next = head;
			head = newElem;
		}
		else
		{
			while (temp->next != nullptr && temp->next->key <= key)
			{
				temp = temp->next;
			}

			newElem->next = temp->next;
			temp->next = newElem;
		}
	}
	catch (const std::bad_alloc &e)
	{
		throw;
	}
}

template<typename type>
const type &PriorityQueue<type>::min() const
{
	return head->data;
}

template<typename type>
void PriorityQueue<type>::removeMin()
{
	PriorityQueueNode<type> *old = head;
	if (head == nullptr)
	{
		throw std::out_of_range("No elements in queue!");
	}
	else
	{
		head = old->next;
		delete old;
	}
}

template<typename type>
std::ostream &operator<<(std::ostream &out, const PriorityQueue<type> &queue)
{
	out.precision(10);
	PriorityQueueNode<type> *temp = queue.head;
	if (temp == nullptr)
	{
		out << "Queue empty\n";
	}
	else
	{
		while (temp != nullptr)
		{
			out << "value: " << temp->getData() << " key: " << temp->getKey() << "\n";
			temp = temp->getNext();
		}
	}
	return out;
}

#endif
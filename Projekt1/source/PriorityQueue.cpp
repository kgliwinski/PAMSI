#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP
#include "../include/PriorityQueue.hh"

template<typename type>
PriorityQueue<type>::PriorityQueue() : head(nullptr) {}

template<typename type>
unsigned int PriorityQueue<type>::size() const
{
    Node* temp = head;
    unsigned int size = 0;

    while(temp!=nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template <typename type>
bool PriorityQueue<type>::isEmpty() const
{
    if (head!=nullptr)
        return false;
    return true;
}

template <typename type>
void PriorityQueue<type>::insert(const type& elem, const unsigned int &key)
{
    
}

template <typename type>
const type &PriorityQueue<type>::min() const
{
    int a = 2;
}

template <typename type>
void PriorityQueue<type>::removeMin()
{
    int a = 2;
}

#endif
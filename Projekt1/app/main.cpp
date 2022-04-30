#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <PriorityQueue.hh>
#include <LinkedList.hh>
#include <iostream>
#include <stdlib.h>

typedef LinkedList<int> intLinkedList;
typedef PriorityQueue<int> intPriorityQueue;

int main()
{
	intPriorityQueue queue;
	queue.insert(12, 1);
	queue.insert(3, 3);
	queue.insert(13,2);
	std::cout << queue;
	queue.removeMin();
	std::cout << queue;
	queue.removeMin();
	std::cout << queue.min() << std::endl;
	queue.removeMin();
	std::cout << queue;
}
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <PriorityQueue.hh>
#include <LinkedList.hh>
#include <iostream>
#include <stdlib.h>

typedef LinkedList<int> IntLinkedList;

int main()
{
	IntLinkedList list;
	list.addFront(5);
	if(!list.isEmpty())
		std::cout << list.front() << std::endl;
	else std::cout << "Pusta lista :)\n";
	list.removeFront();
	if(!list.isEmpty())
		std::cout << list.front() << std::endl;
	else std::cout << "Pusta lista :)\n";
}
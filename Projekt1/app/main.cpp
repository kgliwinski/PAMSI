#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>

#include "../include/PriorityQueue.hh"
#include "../include/LinkedList.hh"
#include "../include/Message.hh"

typedef LinkedList<int> intLinkedList;
typedef PriorityQueue<int> intPriorityQueue;

int main()
{
	std::string fileName = "../messages/message1.txt";
	Message mess;
	mess.readFromFile(fileName);
	std::cout << mess;

}
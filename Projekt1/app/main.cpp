#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>

#include "../include/LinkedList.hh"
#include "../include/Message.hh"
#include "../include/PriorityQueue.hh"

int main()
{
	std::string fileName;
	std::cout << "Enter the fileName of message (e.g. '../messages/test.txt')" << std::endl;
	std::cin >> fileName;
	Message mess(fileName);
	if (mess.readFromFile())
	{
		std::cout << mess << std::endl;
		std::cout << mess.returnPrint() << std::endl;
	}
	else
	{
		std::cout << "Message is broken or doesn't exist - could not decode" << std::endl;
	}

}
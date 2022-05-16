#include <iostream>
#include <stdlib.h>

#include "../include/LessComparator.hh"
#include "../include/MergeSort.hh"
int main()
{
	std::vector<int> vec;
    for(unsigned int i = 0; i < 20; ++i)
    {
        vec.push_back(rand() % 100);
    }

	Less<int> oper;
	MergeSort<int, Less<int>>(vec, oper);
	std::vector<int>::iterator iter = vec.begin();
	while (*iter != vec.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
}
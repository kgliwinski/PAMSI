#include <iostream>
#include <stdlib.h>

#include "../include/LessComparator.hh"
#include "../include/MergeSort.hh"
int main()
{
	std::vector<int> vec = { 1, 5, 2, 3, 4, 6 };
	Less<int> oper;
	MergeSort<int, Less<int>>(vec, oper);
	std::vector<int>::iterator iter = vec.begin();
	while (*iter != vec.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
}
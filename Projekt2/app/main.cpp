#include <iostream>
#include <stdlib.h>

#include "../include/LessComparator.hh"
#include "../include/MergeSort.hh"
#include "../include/QuickSort.hh"
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
	std::cout<<"Merge Sort\n";
	while (*iter != vec.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
	std::vector<int> vec1;
    for(unsigned int i = 0; i < 20; ++i)
    {
        vec1.push_back(rand() % 100);
    }

	MergeSort<int, Less<int>>(vec1, oper);
	iter = vec1.begin();
	std::cout << "Quick Sort\n";
	while (*iter != vec1.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
}
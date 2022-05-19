#include <iostream>
#include <stdlib.h>

#include "../include/LessComparator.hh"
#include "../include/MergeSort.hh"
#include "../include/QuickSort.hh"
#include "../include/BucketSort.hh"

int main()
{
	std::vector<int>::iterator iter;
	Less<int> oper;
	/*
	std::vector<int> vec;
	for (unsigned int i = 0; i < 30; ++i)
	{
		vec.push_back(rand() % 1000);
	}

	
	MergeSort<int, Less<int>>(vec, oper);
	
	std::cout << "Merge Sort\n";
	while (*iter != vec.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
	std::vector<int> vec1;
	for (unsigned int i = 0; i < 30; ++i)
	{
		vec1.push_back(rand() % 1000);
	}

	QuickSort<int, Less<int>>(vec1, oper);
	iter = vec1.begin();
	std::cout << "Quick Sort\n";
	while (*iter != vec1.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
	*/
	std::vector<int> vec2;
	for (unsigned int i = 0; i < 30; ++i)
	{
		vec2.push_back(rand() % 1000);
	}

	iter = vec2.begin();
	std::cout << "Before\n";
	while (*iter != vec2.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;

	BucketSort<int, Less<int>>(vec2, oper);
	iter = vec2.begin();
	std::cout << "Bucket Sort\n";
	while (*iter != vec2.back())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << *iter++ << " " << std::endl;
}
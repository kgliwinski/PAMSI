#ifndef BUCKET_SORT_HH
#define BUCKET_SORT_HH
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

#include "../include/QuickSort.hh"

template<typename type, typename comp>
void BucketSort(std::vector<type> &vec, const comp &less)
{
	unsigned int i, j, count = vec.size();
	if (count <= 1)
	{
		return;
	}
	type maxVal = *std::max_element(vec.begin(), vec.end());
	type minVal = *std::min_element(vec.begin(), vec.end());
	const unsigned int n = maxVal - minVal + 1;

	std::vector<type> *bucks = new std::vector<type>[n];
	for (i = 0; i < count; ++i)
	{
		bucks[vec.at(i) - minVal].push_back(vec.at(i));
	}

	for (i = 0; i < n; ++i)
	{
		MergeSort(bucks[i], less);
	}
	unsigned int index = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < bucks[i].size(); ++j)
		{
			vec[index++] = bucks[i].at(j);
		}
	}
	delete[] bucks;
}

#endif
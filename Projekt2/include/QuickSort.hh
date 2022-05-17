#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH

#include <stdio.h>
#include <vector>

template<typename type, typename comp>
void QuickSort(std::vector<type> &vec, const comp &less)
{
	if (vec.size() <= 1)
	{
		return;
	}
	QuickSortStep(vec, 0, vec.size() - 1, less);
}

template<typename type, typename comp>
void QuickSortStep(std::vector<type> &vec, int a, int b, const comp &less)
{
	if (a >= b)
	{
		return;
	}
	type pivot = vec[b];
	int l = a;
	int r = b - 1;
	while (l <= r)
	{
		while (l <= r && !less(pivot, vec[l]))
		{
			l++;
		}
		while (r >= l && !less(vec[r], pivot))
		{
			r--;
		}
		if (l < r)
		{
			std::swap(vec[l], vec[r]);
		}
	}
	std::swap(vec[l], vec[b]);
	QuickSortStep(vec, a, l - 1, less);
	QuickSortStep(vec, l + 1, b, less);
}

#endif
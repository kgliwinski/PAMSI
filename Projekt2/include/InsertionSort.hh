#ifndef INSERTION_SORT_HH
#define INSERTION_SORT_HH

#include <stdlib.h>
#include <vector>

template<typename type, typename comp>
void InsertionSort(std::vector<type> &vec, const comp &less)
{
	unsigned int i, key, j, n = vec.size();
	if (n <= 1)
	{
		return;
	}
    for(i = 1; i < n; ++i)
    {
        key = vec.at(i);
        j = i - 1;
        while(j >= 0 && less( key, vec.at(j)) )
        {
            vec.at(j+1) = vec.at(j);
            j = j-1;
        }
        vec.at(j+1) = key;
    }
}

#endif
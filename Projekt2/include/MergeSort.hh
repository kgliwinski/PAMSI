#ifndef MERGE_SORT_HH
#define MERGE_SORT_HH

#include <stdlib.h>
#include <vector>

template<typename type, typename comp>
bool MergeSort(std::vector<type> &elems, const comp &less);

template<typename type, typename comp>
void Merge(std::vector<type> &in, std::vector<type> &out, const comp& less, unsigned int b, unsigned int m);
#include "../source/MergeSort.cpp"
#endif
#ifndef MERGE_SORT_HH
#define MERGE_SORT_HH

#include <stdlib.h>
#include <vector>

template<typename type, typename comp>
void MergeSort(std::vector<type> &elems, const comp &less)
{
    unsigned int n = elems.size(), m, b;
    if(n <= 1)
    {
        return;
    }
    std::vector<type> v1(elems);
    std::vector<type>* in = &v1;
    std::vector<type> v2(n);
    std::vector<type>* out = &v2;
	for(m = 1; m < n; m*=2)
    {
        for(b = 0; b < n; b+= 2*m)
        {
            Merge(*in, *out, less, b, m);
        }
        std::swap(in, out);
    }
    elems = *in;
}

template<typename type, typename comp>
void Merge(std::vector<type> &in, std::vector<type> &out, const comp& less, unsigned int b, unsigned int m)
{
    unsigned int i = b, j = b + m, n = in.size(),
    e1 = std::min(b+m, n), e2 = std::min(b+ 2*m, n), k = b;
    while((i < e1) && (j < e2))
    {
        if(!less(in[j], in[i]))
        {
            out[k++] = in[i++];
        }
        else
        {
            out[k++] = in[j++];
        }
    }
    while(i < e1)
    {
        out[k++] = in[i++];
    }
    while(j < e2)
    {
        out[k++] = in[j++];
    }
}

#endif
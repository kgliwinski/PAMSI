#include "../include/MergeSort.hh"

template<typename type, typename comp>
bool MergeSort(std::vector<type> &elems, const comp &less)
{
	typedef std::vector<type> vect;
    unsigned int n = elems.size(), m, b;
    if(n <= 1)
    {
        return 0;
    }
    vect v1(elems);
    vect* in = &v1;
    vect v2(n);
    vect* out = &v2;
	for(m = 1; m < n; m*=2)
    {
        for(b = 0; b < n; b+= 2*m)
        {
            Merge(*in, *out, less, b, m);
        }
        std::swap(in, out);
    }
    elems = *in;
    return 1;
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
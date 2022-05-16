#ifndef LESS_COMPARATOR_HH
#define LESS_COMPARATOR_HH
#include <stdlib.h>
#include <vector>

template<typename type>
class Less
{
	public:
	bool operator()(const type &left, const type &right) const { return left < right; }
};

#endif
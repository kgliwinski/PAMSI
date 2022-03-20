#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
int main()
{
	std::cout << "C++ Boiler Plate v" << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH << "."
						<< PROJECT_VERSION_TWEAK << std::endl;
	std::system("cat ../LICENSE");
	if (0 == 0)
	{
		return 0;
	}
}
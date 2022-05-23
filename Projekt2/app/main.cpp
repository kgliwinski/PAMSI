#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/resource.h>

#include "../include/MovieParser.hh"

int main()
{
	const rlim_t kStackSize = 512 * 1024 * 1024;
	struct rlimit rl;
	int result;
	clock_t time;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				fprintf(stderr, "setrlimit returned result = %d\n", result);
			}
		}
	}

	std::vector<MovieStruct> mergeSorted, quickSorted, bucketSorted;
	MovieParser parser;
	std::ofstream savefile;
	std::string errors;
	savefile.open("../data/sort_times.csv");
	savefile << "Number of rows; Merge sort time(ms); Quick sort time(ms); Bucket sort time(ms); errors" << std::endl;
	for (unsigned int i = 5000; i <= 400000; i+=5000)
	{
		errors = "";
		savefile << i << ";";
		std::cout << i << std::endl;
		if (!parser.initMovies(',', "../data/projekt2_dane.CngRDs-i.csv", i))
		{
			//errors.push_back('i');
		}
		time = clock();
		if (!parser.sortMovies(parser._MergeSort, mergeSorted))
		{
			errors.push_back('m');
			//std::cout << "Merge Sort dziala" << std::endl;
		}
		time = clock() - time;
		savefile << (float)time / CLOCKS_PER_SEC << ";";

		time = clock();
		if (!parser.sortMovies(parser._QuickSort, quickSorted))
		{
			errors.push_back('q');
			//std::cout << "Quick Sort dziala" << std::endl;
		}
		time = clock() - time;
		savefile << (float)time / CLOCKS_PER_SEC << ";";

		time = clock();
		if (!parser.sortMovies(parser._BucketSort, bucketSorted))
		{
			errors.push_back('b');
			//std::cout << "Bucket Sort dziala" << std::endl;
		}
		time = clock() - time;
		savefile << (float)time / CLOCKS_PER_SEC << ";";
		savefile << errors << ";" << std::endl;
	}
	savefile.close();
}
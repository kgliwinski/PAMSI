#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "../include/BucketSort.hh"
#include "../include/MergeSort.hh"
#include "../include/QuickSort.hh"
#include "../include/LessComparator.hh"
#include<vector>
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include<vector>
#include<stdlib.h>

TEST_CASE("MergeSort test #1 - 100 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 100; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    BucketSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("MergeSort test #2 - 10000 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 10000; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    BucketSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("MergeSort test #3 - 100000 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 100000; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    BucketSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("QuickSort test #1 - 100 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 100; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    QuickSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("QuickSort test #2 - 10000 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 10000; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    QuickSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("QuickSort test #3 - 100000 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 100000; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    QuickSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("BucketSort test #1 - 100 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 100; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    BucketSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("BucketSort test #2 - 10000 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 10000; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    BucketSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}

TEST_CASE("BucketSort test #3 - 100000 elems")
{
    std::vector<int> preSort, mySort, stdSort;
    Less<int> oper;
    for(unsigned int i = 0; i < 100000; ++i)
    {
        preSort.push_back(rand() % 10000);
    }
    mySort = preSort;
    stdSort = preSort;

    BucketSort<int, Less<int>>(mySort, oper);
    std::sort(stdSort.begin(), stdSort.end());

    CHECK(mySort == stdSort);
    CHECK(mySort != preSort);
}
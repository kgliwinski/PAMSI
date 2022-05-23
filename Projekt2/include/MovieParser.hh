#ifndef MOVIE_PARSER_HH
#define MOVIE_PARSER_HH

#include "CsvParser.hh"

#include "../include/LessComparator.hh"
#include "../include/MergeSort.hh"
#include "../include/QuickSort.hh"
#include "../include/BucketSort.hh"


struct MovieStruct
{
    std::string name;
    unsigned int rating;
    bool operator <(const MovieStruct &secMovie) const
    {
        return (this->rating < secMovie.rating && this->name.compare(secMovie.name));
    }
    unsigned int operator -(const MovieStruct &secMovie) const
    {
        return this->rating - secMovie.rating;
    }
    operator unsigned int() const
    {
        return this->rating;
    }
};

class MovieParser
{
    private:
    std::vector<MovieStruct> movies;
    public:
    enum SortTypes {_MergeSort = 0, _QuickSort, _BucketSort};

    explicit MovieParser() = default;
    bool initMovies(const char &delimiter, const std::string &filename, const unsigned int &maxLine);
    bool sortMovies(unsigned int sortType, std::vector<MovieStruct> &sortedMoviess) const;
};

#endif
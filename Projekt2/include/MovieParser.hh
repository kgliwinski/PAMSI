#ifndef MOVIE_PARSER_HH
#define MOVIE_PARSER_HH

#include "CsvParser.hh"
#include "iostream"
struct MovieStruct
{
    std::string name;
    unsigned int rating;
    bool operator <(const MovieStruct &secMovie) const
    {
        return this->rating < secMovie.rating;
    }
};

class MovieParser
{
    private:
    std::vector<MovieStruct> movies;
    public:
    enum SortTypes {_MergeSort = 0, _QuickSort, _InsertionSort};

    explicit MovieParser() = default;
    bool initMovies(const char &delimiter, const std::string &filename);
};

#endif
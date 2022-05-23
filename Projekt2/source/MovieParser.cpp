#include "../include/MovieParser.hh"

bool MovieParser::initMovies(const char &delimiter, const std::string &filename, const unsigned int &maxLine)
{
	movies.clear();
	CsvParser<3> parser;
	unsigned int i;
	MovieStruct singleMovie;
	parser.readFile(delimiter, filename, maxLine);

	for (i = 1; i < parser.colsData[0].size(); ++i)
	{
		singleMovie.name = parser.colsData[1].at(i);
		if (parser.colsData[2].at(i) == "") // for the case of no number
		{
			parser.colsData[2].at(i) = "0.0";
		}
		singleMovie.rating = (unsigned int)(std::stof(parser.colsData[2].at(i)));
		movies.push_back(singleMovie);
	}
	return movies.size() == parser.colsData[1].size() - 1;
}

bool MovieParser::sortMovies(unsigned int sortType, std::vector<MovieStruct> &sortedMovies) const
{
	if (sortType > 2)
		return 0;
	Less<MovieStruct> oper;
	sortedMovies = this->movies;
	switch (sortType)
	{
	case _MergeSort:
	{
		MergeSort<MovieStruct, Less<MovieStruct>>(sortedMovies, oper);
		break;
	}
    case _QuickSort:
    {
        QuickSort<MovieStruct, Less<MovieStruct>>(sortedMovies, oper);
        break;
    }
    case _BucketSort:
    {
        BucketSort<MovieStruct, Less<MovieStruct>>(sortedMovies, oper);
        break;
    }
    default:
    {
        return 0;
        break;
    }
	}
    return 1;
}
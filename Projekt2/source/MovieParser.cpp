#include "../include/MovieParser.hh"

bool MovieParser::initMovies(const char &delimiter, const std::string &filename)
{
	CsvParser<3> parser;
	unsigned int i;
	MovieStruct singleMovie;
	parser.readFile(delimiter, filename);

	for (i = 1; i < parser.colsData[0].size(); ++i)
	{
		singleMovie.name = parser.colsData[1].at(i);
        if(parser.colsData[2].at(i) == "") // for the case of no number
        {
            parser.colsData[2].at(i) = "0.0";
        }
		singleMovie.rating = (unsigned int)(std::stof(parser.colsData[2].at(i)) * 10);
		movies.push_back(singleMovie);
	}
	return movies.size() == parser.colsData[1].size() - 1;
}
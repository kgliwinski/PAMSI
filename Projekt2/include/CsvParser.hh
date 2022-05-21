#ifndef CSV_PARSER_HH
#define CSV_PARSER_HH

#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

template<unsigned int colsNum>
class CsvParser
{
	protected:
	std::vector<std::string> colsData[colsNum];

	public:
	CsvParser();
	~CsvParser() = default;
	bool readFile(char delimiter, std::string filename);
	bool processLine(char delimiter, std::string line);

	unsigned int getVectorSize() { return colsData[0].size(); }
};

template<unsigned int colsNum>
CsvParser<colsNum>::CsvParser()
{
	if (colsNum == 0)
	{
		throw std::length_error("Columns number can't be 0");
	}
}

template<unsigned int colsNum>
bool CsvParser<colsNum>::readFile(char delimiter, std::string filename)
{
	std::ifstream file;
	file.open(filename, std::ios::in);
	if (file.fail())
	{
		return 0;
	}
	for (std::string lines; std::getline(file, lines);)
	{
		if (!processLine(delimiter, lines)) {}
	}
	return 1;
}

template<unsigned int colsNum>
bool CsvParser<colsNum>::processLine(char delimiter, std::string line)
{
	unsigned int i = 0;
	char sign;
	std::string words[colsNum];
	for (std::string::size_type j = 0; j < line.size(); ++j)
	{
		sign = line.at(j);
		if (sign == delimiter)
		{
			i++;
			if (i >= colsNum)
			{
				return 0;
			}
		}
		else
		{
			words[i].push_back(sign);
		}
		j++;
	}
	for (i = 0; i < colsNum; ++i)
	{
		colsData[i].push_back(words[i]);
	}
	return 1;
}

#endif
#include "CustomFunctions/CSVReader.h"
CSVReader::CSVReader()
{
	filename = "";
	delim = "";
}

std::vector<std::vector<int>> CSVReader::ReadCSV(std::string filename)
{
	std::vector<std::vector<int>> dataInt;
	std::ifstream fileStream(filename, std::ios::in);
	std::string line;
	delim = ",";
	std::vector<std::vector<std::string>> tmpData;
	while (std::getline(fileStream, line))
	{
		std::stringstream lineStream(line);
		std::string cell;
		std::vector<std::string> row;
		while (std::getline(lineStream, cell, ','))
		{
			row.push_back(cell);
		}

		tmpData.push_back(row);
	}

	for (int i = 0; i < tmpData.size(); ++i)
	{
		std::vector<int> tmp;
		for (int j = 0; j < tmpData[0].size(); ++j)
		{
			tmp.push_back(std::stoi(tmpData[i][j]));
		}

		dataInt.push_back(tmp);
	}

	return dataInt;
}

CSVReader::~CSVReader() {}
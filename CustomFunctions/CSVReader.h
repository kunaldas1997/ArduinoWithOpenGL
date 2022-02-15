#pragma once


#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class CSVReader
{

public:
	CSVReader();
	std::vector<std::vector<int>> ReadCSV(std::string filename);
	
	~CSVReader();
private:
	std::string filename;
	std::string delim;
};


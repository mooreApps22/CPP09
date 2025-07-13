#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include "data.hpp" 


std::string	validateInputFilename(char *argv)
{
	std::string	inputFile(argv);
	if (inputFile.empty())
		std::cerr << "Expected usages: ./btc <data.csv>" << std::endl;
	return (inputFile);
}

Map	validateBitcoinDatabase(std::string database)	
{
	std::ifstream	csv(database.c_str());
	if (!csv)
	{
		std::cerr << "Error: " << " could not open " << database << std::endl;
		return (Map());
	}
	Map				btc;
	std::string		line;

	std::getline(csv, line);
	if (line != "date,exchange_rate")
		std::cerr << "Error: " << database << " has unexpected CSV header format" << std::endl;
	while (std::getline(csv, line))
	{
		std::stringstream	lineStream(line);
		std::string			date, rate;

		std::getline(lineStream, date, ',');
		std::getline(lineStream, rate); // default delim is \n
		// maybe need to trim here
		btc[date] = std::atof(rate.c_str());
	}
	if (btc.empty())
		std::cerr << database << ": empty of data" << std::endl;
	return (btc);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Expected usages: ./btc <data.csv>" << std::endl;
		return (1);
	}
	std::string		inputFile = validateInputFilename(argv[1]);
	Map				btc = validateBitcoinDatabase("data.csv");

	if (inputFile.empty() || btc.empty())
		return (1);
	outputExchangeRates(inputFile, btc);
	return (0);
	
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include "data.hpp" 

static std::string	trim(const std::string& str)
{
	size_t	first = str.find_first_not_of(" \t");

	if (first == std::string::npos)
		return "";

	size_t	last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

static bool	isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

void	outputExchangeRates(std::string	filename, Map btc)
{
	std::ifstream	file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string		line;

	std::getline(file, line);
	if (line != "date | value")
		std::cerr << "Error: " << filename << " has unexpected input file header format" << std::endl;

	while (std::getline(file, line))
	{
		std::stringstream	lineStream(line);
		std::string			date, valueStr;

		if (line.find('|') == std::string::npos) {
			std::cerr << "Error: bad input => " << line <<  std::endl;
			continue ;
		}
		std::getline(lineStream, date, '|');
		std::getline(lineStream, valueStr);
		date = trim(date);
		valueStr = trim(valueStr);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date <<  std::endl;
			continue ;
		}

		double				valueDouble;
		std::stringstream	valueStream(valueStr);

		if (!(valueStream >> valueDouble) || valueDouble < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (valueDouble > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		Map::iterator it = btc.lower_bound(date);

		if (it == btc.end() || it->first != date) {
			if (it == btc.begin()) {
				std::cerr << "Error: no eariler date found for " << date << std::endl;
				continue ;
			}
			--it;
		}

		double rate = it->second;
		double result = valueDouble * rate;

		std::cout << date << " => " << valueDouble << " = " << result << std::endl;
	}
		
}

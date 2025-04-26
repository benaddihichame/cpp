#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <sstream>
#include <fstream>


class BitcoinExchange
{
	private:
		std::map<std::string, float> exchangeRate;
	public:
	~BitcoinExchange();
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &cpy);
	void loadDatabase(const std::string &filename);
	void processInputFile(const std::string &filename);
	bool isValideDate(const std::string &date)const;
	bool isValideValue(const float value)const;
	
};

#endif
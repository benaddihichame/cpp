#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <sstream>
#include <fstream>
#include <cstdlib>


class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::map<std::string, float> mapi;
		bool isValideDate(const std::string &date)const;
	public:
		~BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &cpy);
		std::map<std::string, float> loadDatabase(const std::string &filename)const;
		void handleInputFile(const std::string &filename) const;	
};

#endif
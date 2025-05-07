#include "BitcoinExchange.hpp"


BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const std::string &filename):mapi(loadDatabase(filename))
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy):mapi(cpy.mapi)
{}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
		mapi = cpy.mapi;
	return *this;
}


bool BitcoinExchange::isValideDate(const std::string &date)const
{
	int year, month, day;
	
	if (date.length() != 10)
		return false;
	if (date[4] != '-'|| date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i ++)
	{
		if (i != 4 && i!= 7 && !isdigit(date[i]))
			return false;
	}

	try{
		year = std::atoi(date.substr(0,4).c_str());
		month = std::atoi(date.substr(5,2).c_str());
		day = std::atoi(date.substr(8,2).c_str());
	}catch (const std::exception&)
	{
		return false;
	}
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year %400 == 0)
		daysInMonth[2] = 29;
	return day <= daysInMonth[month];
}
	
std::map<std::string, float> BitcoinExchange::loadDatabase(const std::string &filename) const
{
	std::map<std::string, float> data;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	std::getline(file, line);
	while (getline(file, line))
	{
		size_t sep = line.find(",");
		if (sep == std::string::npos)
			throw std::runtime_error("Error: invalide format => " + line);
		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep +1);
		if (!isValideDate(date))
			throw std::runtime_error("Error: Invalide date");
		std::istringstream iss(valueStr);
		float value;
		iss >> value;
		if (iss.fail())
			throw std::runtime_error("Error: invalide value in data file => " + valueStr);
		data[date] = value;
	}
	return data;
}

void	BitcoinExchange::handleInputFile(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: coul not open file");

	std::string line;
	std::getline(file, line);
	
	while (std::getline(file, line))
	{
		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);
		if (!isValideDate(date))
		{
            std::cerr << "Error: invalid date format => " << date << std::endl;
            continue;
        }

		std::istringstream iss(valueStr);
		float value;
		iss >> value;
		if (iss.fail() || value > 1000 || value < 0)
		{
			if (value > 1000)
				std::cerr << "Error: too large number" << std::endl;
			else if (value < 0)
				std::cerr << "Error: not a positive number" << std::endl;
			else
				std::cerr << "Error: invaide valuer" << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = mapi.lower_bound(date);
		if (it == mapi.end() || it->first != date)
		{
			if( it == mapi.begin())
			{
				std::cerr << "Error: no valid date found for => " << date << std::endl;
				continue;
			}
			--it;
		}

		float exchangeRate = it->second;
		float result = value * exchangeRate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}
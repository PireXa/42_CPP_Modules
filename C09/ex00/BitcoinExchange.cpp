#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->setMap();
}

BitcoinExchange::BitcoinExchange(std::string const & name, double const & price)
{
	this->setMap();
	this->exchange[name] = price;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		this->exchange = rhs.exchange;
	}
	return (*this);
}

void	BitcoinExchange::setMap()
{
	std::string read;
	std :: ifstream ifs("data.csv");
	getline(ifs, read);
	while (getline(ifs, read))
	{
		this->exchange[read.substr(0, read.find(','))] = std::strtod(read.substr(read.find(',') + 1).c_str(), NULL);
	}
	ifs.close();
}

void	BitcoinExchange::printMap()
{
	std::map<std::string, double>::iterator it = this->exchange.begin();
	while (it != this->exchange.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}

void	BitcoinExchange::searchMap(std::string const & search_string)
{
	long double		quantity = std::strtod(search_string.substr(search_string.find('|') + 1).c_str(), NULL);
	std::map<std::string, double>::iterator it = this->exchange.find(search_string.substr(0, search_string.find(' ')));
	std::cout << std::setprecision(2) << std::fixed;
	if (it != this->exchange.end())
		std::cout << search_string.substr(0, search_string.find(' ')) << "  " << quantity << "btc =|=|=> " << it->second * quantity << " dinehriso" << std::endl;
	else
	{
		it = this->exchange.lower_bound(search_string.substr(0, search_string.find(' ')) + " ");
		it--;
		std::cout << search_string.substr(0, search_string.find(' ')) << "  " << quantity << "btc =|=|=> " << it->second * quantity << " dinehriso" << std::endl;
	}
}

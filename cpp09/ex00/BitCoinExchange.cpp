#include "BitCoinExchange.hpp"
#include <fstream>
#include <sstream>

bool validDate(const std::string &date)
{
    std::istringstream iss(date);
    int year, month, day;
    char dash1, dash2;
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
        return (false);
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        return (false);
    if (month == 2)
    {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leap ? 29 : 28))
            return (false);
    }
    return (true);
}

float stringToFloat(const std::string &str)
{
    std::istringstream iss(str);
    float value;
    iss >> value;
    return (value);
}

BitCoinExchange::BitCoinExchange() { throw std::runtime_error("Default constructor is not allowed."); }

BitCoinExchange::~BitCoinExchange() {}

BitCoinExchange::BitCoinExchange(const char * filename) : _filename(filename)
{
    std::ifstream file(DATA_CSV_FILE);
    if (!file.is_open())
        throw std::runtime_error("Failed to open data file.");
    std::string line;
    // skip header
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, line.find(','));
        float rate = stringToFloat(line.substr(line.find(',') + 1));
        _data[date] = rate;
    }
    file.close();
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange &other) { *this = other; }

BitCoinExchange& BitCoinExchange::operator=(const BitCoinExchange &other)
{
    if (this != &other)
    {
        _filename = other._filename;
        _data = other._data;
    }
    return (*this);
}

int BitCoinExchange::readFile()
{
    std::ifstream file(_filename.c_str());
    if (!file.is_open())
        return (-1);
    std::string line;
    std::getline(file, line);
    if (line != DATA_CSV_HEADER)
        return (-1);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;
        if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr))
        {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }
        date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
        if (!validDate(date))
        {
            std::cerr << "Error: Invalid date => " << date << std::endl;
            continue;
        }
        valueStr.erase(std::remove(valueStr.begin(), valueStr.end(), ' '), valueStr.end());
        float value = stringToFloat(valueStr);
        if (value < 0)
            std::cerr << "Error: Not a positive number." << std::endl;
        else if (value > 1000)
            std::cerr << "Error: Too large a number." << std::endl;
        else if (valueStr.find_first_not_of("0123456789.") != std::string::npos)
            std::cerr << "Error: Invalid value format." << std::endl;
        else
            calculateResult(date, value);
    }
    file.close();
    return (0);
}

void BitCoinExchange::calculateResult(std::string date, float value) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.end())
    {
        std::cerr << "Error: Date not found in data file." << std::endl;
        return ;
    }
    if (it->first != date)
    {
        if (it == _data.begin())
        {
            std::cerr << "Error: Date not found in data file." << std::endl;
            return ;
        }
        --it;
    }
    std::string closestDate = it->first;
    float rate = it->second;
    float result = value * rate;
    std::cout << date << " => " << value << " = " << result << std::endl;
    return ;
}

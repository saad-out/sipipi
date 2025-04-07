#pragma once

#include <algorithm>
#include <iostream>
#include <map>

#define DATA_CSV_FILE "./data.csv"
#define DATA_CSV_HEADER "date | value"

class BitCoinExchange
{
    public:
        BitCoinExchange();
        ~BitCoinExchange();
        BitCoinExchange(const char * filename);
        BitCoinExchange(const BitCoinExchange &other);
        BitCoinExchange & operator = (const BitCoinExchange &other);

        int readFile();
        void calculateResult(std::string date, float value) const;

    private:
        std::string _filename;
        std::map<std::string, float> _data;
};

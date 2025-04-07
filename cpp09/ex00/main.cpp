#include <iostream>
#include "BitCoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Usage: ./btc <filename>" << std::endl, 1);
    BitCoinExchange btc(av[1]);
    if (btc.readFile() == -1)
        return (std::cerr << "Error: Invalid file format." << std::endl, 1);
    return (0);
}

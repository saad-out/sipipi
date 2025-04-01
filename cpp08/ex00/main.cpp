#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>

int main()
{
    // test vector
    std::vector<int> vec = {4, 0, -2093, 10};
    try {
        std::cout << "Value found in vector: " << easyfind(vec, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found in vector" << std::endl;
    }

    // test array
    std::array<int, 4> arr = {4, 0, -2093, 10};
    try {
        std::cout << "Value found in array: " << easyfind(arr, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found in array" << std::endl;
    }

    // test list
    std::list<int> lst = {4, 0, -2093, 10};
    try {
        std::cout << "Value found in list: " << easyfind(lst, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found in list" << std::endl;
    }

    // test value not found
    try {
        std::cout << "Value found in list: " << easyfind(lst, 100) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Value not found in list" << std::endl;
    }

    return (0);
}

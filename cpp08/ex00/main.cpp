#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>

int main()
{
    std::vector<int> vec = {4, 0, -2093, 10};
    std::cout << easyfind(vec, 0) << std::endl;
    /*easyfind(vec, 0);*/

    std::array<int, 4> arr = {4, 0, -2093, 10};
    std::cout << easyfind(arr, 0) << std::endl;
    /*easyfind(arr, 0);*/

    /*std::list<int> lst = {4, 0, -2093, 10};*/
    /*std::cout << easyfind(lst, 0) << std::endl;*/
    return (0);
}

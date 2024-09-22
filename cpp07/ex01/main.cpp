#include "iter.hpp"

int main()
{
    int intArr[5] = {-1, 0, 1, 2, 3};
    iter(intArr, 5, print);

    char name[5] = {"hala"};
    iter(name, 5, print);

    return (0);
}

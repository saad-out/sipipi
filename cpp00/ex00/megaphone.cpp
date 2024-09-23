#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        for (size_t j = 0; av[i][j] != '\0'; j++)
            std::cout << (char)toupper(av[i][j]);
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}

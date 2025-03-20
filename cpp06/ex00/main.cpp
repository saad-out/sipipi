#include "ScalarConverter.hpp"
#include <limits>

int main(int ac, char **av) {
  if (ac < 2)
    return (1);

  for (int i = 1; i < ac; i++) {
    ScalarConverter::convert(av[i]);
    if (i + 1 < ac)
      std::cout << std::endl;
  }
  return (0);
}

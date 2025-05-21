#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac == 2) {
    RPN rpn;
    try {
      std::cout << rpn.calculate(av[1]) << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
    }
  } else {
    std::cerr << "Error: Invalid number of arguments" << std::endl;
    return (1);
  }
  return (0);
}

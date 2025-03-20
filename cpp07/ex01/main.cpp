#include "iter.hpp"

int main() {
  int intArr[5] = {-1, 0, 1, 2, 3};
  std::cout << "Printing int array" << std::endl;
  iter(intArr, 5, print);

  char name[5] = {"hala"};
  std::cout << "Printing char array" << std::endl;
  iter(name, 4, print);

  return (0);
}

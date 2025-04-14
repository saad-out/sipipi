#include "PmergeMe.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(int ac, char **av) {
  if (ac < 2) {
    std::cerr << "Error: No arguments provided." << std::endl;
    return 1;
  }
  std::vector<int> numbers = PmergeMe::parseArguments(ac - 1, av + 1);
  if (numbers.empty()) {
    std::cerr << "Error: No valid numbers provided." << std::endl;
    return 1;
  }
  std::cout << "Before: ";
  for (size_t i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i];
    if (i < numbers.size() - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
  std::vector<int> sortedNumbersWithVector = PmergeMe::sortVector(numbers);
  std::list<int> sortedNumbersWithList = PmergeMe::sortList(numbers);

  return (0);
}

#pragma once

#include <iostream>
#include <list>
#include <vector>
class PmergeMe {
public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &rhs);
  static std::vector<int> sortVector(std::vector<int> &numbers);
  static std::list<int> sortList(std::list<int> &numbers);
  static std::vector<int> parseArguments(int ac, char **av);
  static void printVector(const std::vector<int> &vec);
  static void printList(const std::list<int> &lst);
};

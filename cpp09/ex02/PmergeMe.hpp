#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <limits>

class PmergeMe {
public:
  static std::vector<int> parseArguments(int ac, char **av);
  static std::deque<int> vectorToDeque(const std::vector<int> &vec);
  static std::vector<int> MergeInsertionSort_vec(std::vector<int> arr);
  static std::deque<int> MergeInsertionSort_deq(std::deque<int> arr);

private:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &src) = delete;
  PmergeMe &operator=(const PmergeMe &rhs) = delete;
};

#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    // No members to copy
  }
  return *this;
}

static void mergeInsertSortVector(std::vector<int> &vec, int left, int right) {
  if (left >= right)
    return;

  // Use insertion sort for small subarrays
  if (right - left <= 10) {
    for (int i = left + 1; i <= right; ++i) {
      int key = vec[i];
      int j = i - 1;
      while (j >= left && vec[j] > key) {
        vec[j + 1] = vec[j];
        --j;
      }
      vec[j + 1] = key;
    }
    return;
  }

  // Recursively sort halves
  int mid = left + (right - left) / 2;
  mergeInsertSortVector(vec, left, mid);
  mergeInsertSortVector(vec, mid + 1, right);

  // Merge the sorted halves
  std::vector<int> temp;
  int i = left, j = mid + 1;
  while (i <= mid && j <= right) {
    if (vec[i] <= vec[j]) {
      temp.push_back(vec[i++]);
    } else {
      temp.push_back(vec[j++]);
    }
  }
  while (i <= mid)
    temp.push_back(vec[i++]);
  while (j <= right)
    temp.push_back(vec[j++]);

  // Copy back to original vector
  for (int k = 0; k < temp.size(); ++k) {
    vec[left + k] = temp[k];
  }
}

std::vector<int> PmergeMe::sortVector(std::vector<int> &numbers) {
  if (numbers.empty())
    return numbers;

  std::vector<int> sorted = numbers;
  mergeInsertSortVector(sorted, 0, sorted.size() - 1);
  return sorted;
}

static void mergeInsertSortList(std::list<int> &lst) {
  if (lst.size() <= 1)
    return;

  // Use insertion sort for small lists
  if (lst.size() <= 10) {
    for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) {
      std::list<int>::iterator insert_pos = lst.begin();
      while (insert_pos != it && *insert_pos < *it) {
        ++insert_pos;
      }
      if (insert_pos != it) {
        lst.insert(insert_pos, *it);
        it = lst.erase(it);
        --it;
      }
    }
    return;
  }

  // Split the list into two halves
  std::list<int> left, right;
  std::list<int>::iterator middle = lst.begin();
  std::advance(middle, lst.size() / 2);
  left.splice(left.end(), lst, lst.begin(), middle);
  right.splice(right.end(), lst, middle, lst.end());

  // Recursively sort halves
  mergeInsertSortList(left);
  mergeInsertSortList(right);

  // Merge the sorted halves
  std::list<int>::iterator left_it = left.begin();
  std::list<int>::iterator right_it = right.begin();
  while (left_it != left.end() && right_it != right.end()) {
    if (*left_it <= *right_it) {
      lst.splice(lst.end(), left, left_it++);
    } else {
      lst.splice(lst.end(), right, right_it++);
    }
  }
  lst.splice(lst.end(), left);
  lst.splice(lst.end(), right);
}

std::list<int> PmergeMe::sortList(std::list<int> &numbers) {
  if (numbers.empty())
    return numbers;

  std::list<int> sorted = numbers;
  mergeInsertSortList(sorted);
  return sorted;
}

std::vector<int> PmergeMe::parseArguments(int ac, char **av) {
  std::vector<int> numbers;

  for (int i = 1; i < ac; ++i) {
    std::string arg = av[i];
    std::istringstream iss(arg);
    int num;

    if (!(iss >> num) || !iss.eof()) {
      throw std::runtime_error("Error: Invalid argument '" + arg + "'");
    }
    if (num < 0) {
      throw std::runtime_error("Error: Negative number '" + arg + "'");
    }
    numbers.push_back(num);
  }

  return numbers;
}

void PmergeMe::printVector(const std::vector<int> &vec) {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it;
    if (it + 1 != vec.end()) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void PmergeMe::printList(const std::list<int> &lst) {
  for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it;
    if (++it != lst.end()) {
      std::cout << " ";
    }
    --it;
  }
  std::cout << std::endl;
}

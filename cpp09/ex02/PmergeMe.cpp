#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

// Constructor
PmergeMe::PmergeMe() {}

// Destructor
PmergeMe::~PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

// Assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  (void)rhs;
  return *this;
}

// Utility function to generate Jacobsthal numbers
static int jacobsthal(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  int a = 0;
  int b = 1;
  int result = 0;

  for (int i = 2; i <= n; ++i) {
    result = b + 2 * a;
    a = b;
    b = result;
  }

  return result;
}

// Function to compute the insertion sequence based on Jacobsthal numbers
static std::vector<int> getJacobsthalInsertionSequence(int size) {
  std::vector<int> sequence;

  if (size <= 0)
    return sequence;

  // Find the smallest k such that J(k) >= size
  int k = 1;
  while (jacobsthal(k) < size) {
    k++;
  }

  // Generate the insertion sequence
  for (int i = 1; i < k; ++i) {
    int start = jacobsthal(i - 1);
    int end = std::min(jacobsthal(i), size);

    for (int j = end; j > start; --j) {
      sequence.push_back(j);
    }
  }

  return sequence;
}

// Binary search function for vectors
static int binarySearchVector(const std::vector<int> &chain, int left,
                              int right, int value) {
  if (left > right) {
    return left;
  }

  int mid = left + (right - left) / 2;

  if (chain[mid] == value) {
    return mid;
  } else if (chain[mid] > value) {
    return binarySearchVector(chain, left, mid - 1, value);
  } else {
    return binarySearchVector(chain, mid + 1, right, value);
  }
}

// Ford-Johnson sort for vector
std::vector<int> PmergeMe::sortVector(std::vector<int> &numbers) {
  int n = numbers.size();

  // Base cases
  if (n <= 1)
    return numbers;

  // Step 1: Pair elements and sort each pair
  std::vector<std::pair<int, int>> pairs;
  bool hasUnpairedElement = (n % 2 == 1);
  int unpairedElement = 0;

  for (int i = 0; i < n - (hasUnpairedElement ? 1 : 0); i += 2) {
    int smaller = numbers[i];
    int larger = numbers[i + 1];

    if (smaller > larger) {
      std::swap(smaller, larger);
    }

    pairs.push_back(std::make_pair(smaller, larger));
  }

  // Handle odd number of elements
  if (hasUnpairedElement) {
    unpairedElement = numbers[n - 1];
  }

  // Step 2: Form the main chain with larger elements
  std::vector<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i) {
    mainChain.push_back(pairs[i].second);
  }

  // Step 3: Recursively sort the main chain
  mainChain = sortVector(mainChain);

  // Step 4: Create the pend list (smaller elements from each pair)
  std::vector<int> pendList;
  for (size_t i = 0; i < pairs.size(); ++i) {
    pendList.push_back(pairs[i].first);
  }

  // Step 5: Insert elements from pend list using Jacobsthal ordering
  std::vector<int> result;
  result.push_back(pendList[0]);

  for (size_t i = 0; i < mainChain.size(); ++i) {
    result.push_back(mainChain[i]);
  }

  std::vector<int> insertionSequence =
      getJacobsthalInsertionSequence(pendList.size() - 1);

  for (size_t i = 0; i < insertionSequence.size(); ++i) {
    int index = insertionSequence[i] - 1;

    if (index < static_cast<int>(pendList.size())) {
      int value = pendList[index];
      int pos = binarySearchVector(result, 0, index, value);
      result.insert(result.begin() + pos, value);
    }
  }

  // Insert the unpaired element if exists
  if (hasUnpairedElement) {
    int pos = binarySearchVector(result, 0, result.size() - 1, unpairedElement);
    result.insert(result.begin() + pos, unpairedElement);
  }

  return result;
}

// Binary search function for lists
static std::list<int>::iterator binarySearchList(std::list<int> &lst, int left,
                                                 int right, int value) {
  std::list<int>::iterator it = lst.begin();
  std::advance(it, left);

  int len = right - left + 1;
  if (len <= 0) {
    return it;
  }

  int mid = left + len / 2;
  std::list<int>::iterator midIt = lst.begin();
  std::advance(midIt, mid);

  if (*midIt == value) {
    return midIt;
  } else if (*midIt > value) {
    return binarySearchList(lst, left, mid - 1, value);
  } else {
    return binarySearchList(lst, mid + 1, right, value);
  }
}

// Ford-Johnson sort for list
std::list<int> PmergeMe::sortList(std::list<int> &numbers) {
  int n = numbers.size();

  // Base cases
  if (n <= 1)
    return numbers;

  // Step 1: Pair elements and sort each pair
  std::vector<std::pair<int, int>> pairs;
  bool hasUnpairedElement = (n % 2 == 1);
  int unpairedElement = 0;

  std::list<int>::iterator it = numbers.begin();
  for (int i = 0; i < n - (hasUnpairedElement ? 1 : 0); i += 2) {
    int first = *it++;
    int second = *it++;

    int smaller = first;
    int larger = second;

    if (smaller > larger) {
      std::swap(smaller, larger);
    }

    pairs.push_back(std::make_pair(smaller, larger));
  }

  // Handle odd number of elements
  if (hasUnpairedElement) {
    unpairedElement = numbers.back();
  }

  // Step 2: Form the main chain with larger elements
  std::list<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i) {
    mainChain.push_back(pairs[i].second);
  }

  // Step 3: Recursively sort the main chain
  mainChain = sortList(mainChain);

  // Step 4: Create the pend list (smaller elements from each pair)
  std::vector<int> pendList;
  for (size_t i = 0; i < pairs.size(); ++i) {
    pendList.push_back(pairs[i].first);
  }

  // Step 5: Insert elements from pend list using Jacobsthal ordering
  std::list<int> result;
  result.push_back(pendList[0]);
  result.splice(result.end(), mainChain);

  std::vector<int> insertionSequence =
      getJacobsthalInsertionSequence(pendList.size() - 1);

  for (size_t i = 0; i < insertionSequence.size(); ++i) {
    int index = insertionSequence[i] - 1;

    if (index < static_cast<int>(pendList.size())) {
      int value = pendList[index];
      std::list<int>::iterator insertPos = result.begin();

      // Simple binary search-like approach for list
      int pos = 0;
      std::list<int>::iterator it = result.begin();
      while (pos < index && it != result.end()) {
        if (*it > value) {
          insertPos = it;
          break;
        }
        ++it;
        ++pos;
      }

      if (pos == index && it != result.end() && value < *it) {
        insertPos = it;
      } else if (pos < index) {
        insertPos = it;
      }

      result.insert(insertPos, value);
    }
  }

  // Insert the unpaired element if exists
  if (hasUnpairedElement) {
    std::list<int>::iterator insertPos = result.begin();
    for (insertPos = result.begin(); insertPos != result.end(); ++insertPos) {
      if (*insertPos > unpairedElement) {
        break;
      }
    }
    result.insert(insertPos, unpairedElement);
  }

  return result;
}

// Parse command-line arguments
std::vector<int> PmergeMe::parseArguments(int ac, char **av) {
  std::vector<int> numbers;

  for (int i = 1; i < ac; ++i) {
    std::string arg = av[i];

    // Check if the argument contains only digits
    for (size_t j = 0; j < arg.length(); ++j) {
      if (!std::isdigit(arg[j])) {
        throw std::invalid_argument(
            "Error: Invalid input - non-digit character found.");
      }
    }

    // Convert to integer and check range
    long value = std::atol(arg.c_str());
    if (value > INT_MAX) {
      throw std::out_of_range("Error: Input value exceeds integer range.");
    }

    numbers.push_back(static_cast<int>(value));
  }

  return numbers;
}

// Print a vector
void PmergeMe::printVector(const std::vector<int> &vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i];
    if (i < vec.size() - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

// Print a list
void PmergeMe::printList(const std::list<int> &lst) {
  for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it;
    if (std::distance(it, lst.end()) > 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

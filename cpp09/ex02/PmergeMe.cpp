#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <stdexcept>

std::deque<int> PmergeMe::vectorToDeque(const std::vector<int> &vec) {
  return std::deque<int>(vec.begin(), vec.end());
}

std::vector<int> PmergeMe::parseArguments(int ac, char **av) {
  std::vector<int> numbers;
  for (int i = 1; i < ac; ++i) {
    std::string arg = av[i];
    if (arg.empty()) {
      throw std::invalid_argument("Error: Empty argument provided.");
    }
    for (size_t j = 0; j < arg.length(); ++j) {
      if (!std::isdigit(arg[j])) {
        throw std::invalid_argument(
            "Error: Invalid input - non-digit character found.");
      }
    }
    long value = std::atol(arg.c_str());
    if (value > INT_MAX) {
      throw std::out_of_range("Error: Input value exceeds integer range.");
    }
    numbers.push_back(static_cast<int>(value));
  }
  return numbers;
}

// =================== Vector Implementation ===================
std::vector<int> jacobstalNumbers_vec(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::vector<int> result;
  result.push_back(0);
  if (n >= 1) result.push_back(1);
  for (int i = 2; i <= n; ++i) {
    // J(n) = J(n-1) + 2 * J(n-2)
    long long intValue = result[i - 1] + 2 * result[i - 2];
    if (intValue > (std::numeric_limits<int>::max())) {
      break;
    }
    result.push_back(static_cast<int>(intValue));
    if (result.back() > n) {
      break;
    }
  }
  return result;
}

std::vector<int> generateJacobsthalIndices_vec(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::vector<int> sequence = jacobstalNumbers_vec(n);
  std::vector<int> indices;
  for (size_t i = 1; i < sequence.size(); ++i) {
    for (int j = sequence[i]; j > sequence[i - 1]; j--) {
      if (j <= n)
        indices.push_back(j - 1); // zero-based index
    }
  }
  // add remaining indices
  for (int i = sequence.back() + 1; i <= n; ++i) {
    indices.push_back(i - 1); // zero-based index
  }
  return indices;
}

void binarySearchInsertion_vec(std::vector<int> &arr, int low, int high,
                               int element) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  arr.insert(arr.begin() + low, element);
}

std::vector<int> PmergeMe::MergeInsertionSort_vec(std::vector<int> arr) {
  if (arr.size() <= 1)
    return arr;
  std::vector<int> winners, losers;
  bool unpairedExists = (arr.size() % 2 != 0);
  for (size_t i = 1; i < arr.size(); i += 2) {
    (arr[i] > arr[i - 1])
        ? (winners.push_back(arr[i]), losers.push_back(arr[i - 1]))
        : (winners.push_back(arr[i - 1]), losers.push_back(arr[i]));
  }
  std::vector<int> sortedWinners = MergeInsertionSort_vec(winners);
  if (unpairedExists) {
    binarySearchInsertion_vec(sortedWinners, 0, sortedWinners.size() - 1,
                              arr.back());
  }
  std::vector<int> indices = generateJacobsthalIndices_vec(losers.size());
  for (size_t i = 0; i < indices.size(); ++i) {
    size_t index = indices[i];
    if (index < losers.size()) {
      binarySearchInsertion_vec(sortedWinners, 0, sortedWinners.size() - 1,
                                losers[index]);
    }
  }
  return sortedWinners;
}

// =================== Deque Implementation ===================
std::deque<int> jacobstalNumbers_deq(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::deque<int> result;
  result.push_back(0);
  if (n >= 1) result.push_back(1);
  for (int i = 2; i <= n; ++i) {
    // J(n) = J(n-1) + 2 * J(n-2)
    long long intValue = result[i - 1] + 2 * result[i - 2];
    if (intValue > (std::numeric_limits<int>::max())) {
      break;
    }
    result.push_back(static_cast<int>(intValue));
    if (result.back() > n) {
      break;
    }
  }
  return result;
}

std::deque<int> generateJacobsthalIndices_deq(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::deque<int> sequence = jacobstalNumbers_deq(n);
  std::deque<int> indices;
  for (size_t i = 1; i < sequence.size(); ++i) {
    for (int j = sequence[i]; j > sequence[i - 1]; j--) {
      if (j <= n)
        indices.push_back(j - 1); // zero-based index
    }
  }
  // add remaining indices
  for (int i = sequence.back() + 1; i <= n; ++i) {
    indices.push_back(i - 1); // zero-based index
  }
  return indices;
}

void binarySearchInsertion_deq(std::deque<int> &arr, int low, int high,
                               int element) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  arr.insert(arr.begin() + low, element);
}

std::deque<int> PmergeMe::MergeInsertionSort_deq(std::deque<int> arr) {
  if (arr.size() <= 1)
    return arr;
  std::deque<int> winners, losers;
  bool unpairedExists = (arr.size() % 2 != 0);
  for (size_t i = 1; i < arr.size(); i += 2) {
    (arr[i] > arr[i - 1])
        ? (winners.push_back(arr[i]), losers.push_back(arr[i - 1]))
        : (winners.push_back(arr[i - 1]), losers.push_back(arr[i]));
  }
  std::deque<int> sortedWinners = MergeInsertionSort_deq(winners);
  if (unpairedExists) {
    binarySearchInsertion_deq(sortedWinners, 0, sortedWinners.size() - 1,
                              arr.back());
  }
  std::deque<int> indices = generateJacobsthalIndices_deq(losers.size());
  for (size_t i = 0; i < indices.size(); ++i) {
    size_t index = indices[i];
    if (index < losers.size()) {
      binarySearchInsertion_deq(sortedWinners, 0, sortedWinners.size() - 1,
                                losers[index]);
    }
  }
  return sortedWinners;
}

#include <algorithm>
#include <chrono>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

// Function to find position of an element in a container
template <typename Container>
int findPosition(const Container &arr, int element) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (arr[i] == element) {
      return i;
    }
  }
  return arr.size(); // Element not found
}

// =================== Vector Implementation ===================
std::vector<int> jacobstalNumbers_vec(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::vector<int> result = {0};
  if (n > 0) {
    result.push_back(1);
  }
  for (int i = 2; i <= n; ++i) {
    // J(n) = J(n-1) + 2 * J(n-2)
    result.push_back(result[i - 1] + 2 * result[i - 2]);
  }
  return result;
}

std::vector<int> generateJacobsthalIndices_vec(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::vector<int> sequence = jacobstalNumbers_vec(n);
  std::vector<int> indices;
  for (int i = 1; i < sequence.size(); ++i) {
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

std::vector<int> MergeInsertionSort_vec(std::vector<int> arr) {
  if (arr.size() <= 1)
    return arr;
  std::vector<int> winners, losers;
  std::vector<int> winnerValues; // To track original winner values
  bool unpairedExists = (arr.size() % 2 != 0);
  int lastIndex = unpairedExists ? arr.size() - 2 : arr.size() - 1;

  // Pair elements, keeping track of the original winner values
  for (int i = 1; i <= lastIndex; i += 2) {
    if (arr[i] > arr[i - 1]) {
      winners.push_back(arr[i]);
      losers.push_back(arr[i - 1]);
      winnerValues.push_back(arr[i]); // Store the original value
    } else {
      winners.push_back(arr[i - 1]);
      losers.push_back(arr[i]);
      winnerValues.push_back(arr[i - 1]); // Store the original value
    }
  }

  // Recursively sort winners
  std::vector<int> sortedWinners = MergeInsertionSort_vec(winners);

  // Handle unpaired element
  if (unpairedExists) {
    binarySearchInsertion_vec(sortedWinners, 0, sortedWinners.size() - 1,
                              arr.back());
  }

  // Get insertion order
  std::vector<int> indices = generateJacobsthalIndices_vec(losers.size());

  // Insert losers in Jacobsthal order
  for (int i = 0; i < indices.size(); ++i) {
    int index = indices[i];
    if (index < losers.size()) {
      int loser = losers[index];
      int winner = winnerValues[index];

      // Find position of corresponding winner in sorted list
      int winnerPos = findPosition(sortedWinners, winner);

      // Insert loser using binary search, but only search up to winner position
      binarySearchInsertion_vec(sortedWinners, 0, winnerPos - 1, loser);
    }
  }

  return sortedWinners;
}

// =================== Deque Implementation ===================
std::deque<int> jacobstalNumbers_deq(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::deque<int> result = {0};
  if (n > 0) {
    result.push_back(1);
  }
  for (int i = 2; i <= n; ++i) {
    // J(n) = J(n-1) + 2 * J(n-2)
    result.push_back(result[i - 1] + 2 * result[i - 2]);
  }
  return result;
}

std::deque<int> generateJacobsthalIndices_deq(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative number of terms not allowed.");
  }
  std::deque<int> sequence = jacobstalNumbers_deq(n);
  std::deque<int> indices;
  for (int i = 1; i < sequence.size(); ++i) {
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

std::deque<int> MergeInsertionSort_deq(std::deque<int> arr) {
  if (arr.size() <= 1)
    return arr;
  std::deque<int> winners, losers;
  std::deque<int> winnerValues; // To track original winner values
  bool unpairedExists = (arr.size() % 2 != 0);
  int lastIndex = unpairedExists ? arr.size() - 2 : arr.size() - 1;

  // Pair elements, keeping track of the original winner values
  for (int i = 1; i <= lastIndex; i += 2) {
    if (arr[i] > arr[i - 1]) {
      winners.push_back(arr[i]);
      losers.push_back(arr[i - 1]);
      winnerValues.push_back(arr[i]); // Store the original value
    } else {
      winners.push_back(arr[i - 1]);
      losers.push_back(arr[i]);
      winnerValues.push_back(arr[i - 1]); // Store the original value
    }
  }

  // Recursively sort winners
  std::deque<int> sortedWinners = MergeInsertionSort_deq(winners);

  // Handle unpaired element
  if (unpairedExists) {
    binarySearchInsertion_deq(sortedWinners, 0, sortedWinners.size() - 1,
                              arr.back());
  }

  // Get insertion order
  std::deque<int> indices = generateJacobsthalIndices_deq(losers.size());

  // Insert losers in Jacobsthal order
  for (size_t i = 0; i < indices.size(); ++i) {
    int index = indices[i];
    if (index < static_cast<int>(losers.size())) {
      int loser = losers[index];
      int winner = winnerValues[index];

      // Find position of corresponding winner in sorted list
      int winnerPos = findPosition(sortedWinners, winner);

      // Insert loser using binary search, but only search up to winner position
      binarySearchInsertion_deq(sortedWinners, 0, winnerPos - 1, loser);
    }
  }

  return sortedWinners;
}

// Function to check if arrays are sorted
template <typename Container> bool isSorted(const Container &arr) {
  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}

// Function to generate a random array
std::vector<int> generateRandomArray(int size, int min, int max) {
  std::vector<int> arr(size);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);

  for (int i = 0; i < size; ++i) {
    arr[i] = distrib(gen);
  }

  return arr;
}

// Convert vector to deque
std::deque<int> vectorToDeque(const std::vector<int> &vec) {
  return std::deque<int>(vec.begin(), vec.end());
}

// Main function for benchmarking
int main() {
  // Different array sizes to test
  std::vector<int> sizes = {10, 100, 1000, 5000, 10000};

  for (int size : sizes) {
    std::cout << "=== Testing with array size: " << size << " ===" << std::endl;

    // Generate random array
    std::vector<int> arr = generateRandomArray(size, 1, 10000);
    std::deque<int> arr_deque = vectorToDeque(arr);

    // Time vector implementation
    auto start_vec = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted_vec = MergeInsertionSort_vec(arr);
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_vec = end_vec - start_vec;

    // Time deque implementation
    auto start_deq = std::chrono::high_resolution_clock::now();
    std::deque<int> sorted_deq = MergeInsertionSort_deq(arr_deque);
    auto end_deq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_deq = end_deq - start_deq;

    // Print results
    std::cout << "Vector implementation: " << time_vec.count() << " ms";
    std::cout << " - Sorted: " << (isSorted(sorted_vec) ? "Yes" : "No")
              << std::endl;

    std::cout << "Deque implementation: " << time_deq.count() << " ms";
    std::cout << " - Sorted: " << (isSorted(sorted_deq) ? "Yes" : "No")
              << std::endl;

    std::cout << "Deque/Vector time ratio: "
              << time_deq.count() / time_vec.count() << std::endl;
    std::cout << std::endl;
  }

  return 0;
}

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

// Helper function to calculate elapsed time in microseconds
double calculateElapsedTime(clock_t start, clock_t end) {
  return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

// Helper function to display vector/deque contents
template <typename T> void displayContainer(const T &container) {
  typename T::const_iterator it;
  for (it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  try {
    // Parse the input arguments
    std::vector<int> inputNumbers = PmergeMe::parseArguments(argc, argv);

    if (inputNumbers.empty()) {
      std::cerr << "Error: No valid numbers provided" << std::endl;
      return 1;
    }

    // Display the unsorted sequence
    std::cout << "Before: ";
    displayContainer(inputNumbers);

    // Convert vector to deque for the second container
    std::deque<int> inputDeque = PmergeMe::vectorToDeque(inputNumbers);

    // Time the vector sorting
    clock_t startVec = clock();
    std::vector<int> sortedVec = PmergeMe::MergeInsertionSort_vec(inputNumbers);
    clock_t endVec = clock();

    // Time the deque sorting
    clock_t startDeq = clock();
    std::deque<int> sortedDeq = PmergeMe::MergeInsertionSort_deq(inputDeque);
    clock_t endDeq = clock();

    // Display the sorted sequence (using the vector result)
    std::cout << "After: ";
    displayContainer(sortedVec);

    // Calculate and display timing information
    double vecTime = calculateElapsedTime(startVec, endVec);
    double deqTime = calculateElapsedTime(startDeq, endDeq);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << inputNumbers.size()
              << " elements with std::vector : " << vecTime << " us"
              << std::endl;
    std::cout << "Time to process a range of " << inputDeque.size()
              << " elements with std::deque : " << deqTime << " us"
              << std::endl;

    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
}

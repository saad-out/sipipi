#pragma once

#include <iostream>

template <class T>
class Array {

private:
  T *arr;
  unsigned int n;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  T &operator[](unsigned int index);
  ~Array();

  unsigned int size() const;
  void print_arr();
};

template <class T>
unsigned int Array<T>::size() const { return (n); }

template <class T>
Array<T>::Array() : arr(new T[0]), n(0) {}

template <class T>
Array<T>::Array(unsigned int n) : n(n) {
  arr = new T[n];
  for (unsigned int i = 0; i < n; i++)
    arr[i] = 0;
}

template <class T>
Array<T>::Array(const Array &other) {
  n = other.n;
  arr = new T[n];
  for (unsigned int i = 0; i < n; i++)
    arr[i] = other.arr[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    if (arr)
      delete[] arr;
    n = other.n;
    arr = new T[n];
    for (unsigned int i = 0; i < n; i++)
      arr[i] = other.arr[i];
  }
  return (*this);
}

template <class T>
Array<T>::~Array() {
  if (arr)
    delete[] arr;
}

template <class T>
T &Array<T>::operator[](unsigned int index) {
  if (index >= n)
    throw std::exception();
  return arr[index];
}

template <class T>
void Array<T>::print_arr() {
  for (unsigned int i = 0; i < n; i++)
    std::cout << "obj[" << i << "] = " << arr[i] << std::endl;
}

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T>
void iter(T *array, unsigned int size, void (*func)(T const &))
{
  for (unsigned int i = 0; i < size; i++)
    func(array[i]);
}

template <typename T> void print(T const &t) {
  std::cout << "=> " << t << std::endl;
}

#endif // __ITER_HPP__

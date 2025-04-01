#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::value_type& easyfind(T &arr, int value)
{
    typename T::iterator i = std::find(arr.begin(), arr.end(), value);
    if (i == arr.end())
        throw std::exception();
    return (*i);
}

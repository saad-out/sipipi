#include "Span.hpp"
#include <algorithm>
#include <stdlib.h>

Span::Span() : _n(0), _index(0) {}

Span::Span(unsigned int n) : _n(n), _index(0) {}

Span::~Span() {}

Span::Span(const Span &other)
{
    *this = other;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _n = other._n;
        _index = other._index;
        _array = other._array;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (_index >= _n)
        throw std::exception();
        // throw Span::ArrayFullException();
    _array.push_back(n);
    _index++;
}

int Span::shortestSpan()
{
    if (_index <= 1)
        throw std::exception();
        // throw Span::ArrayEmptyException();
    std::sort(_array.begin(), _array.end());
    int min = 0x7FFFFFFF;
    for (unsigned int i = 1; i < _array.size(); i++)
    {
        if (_array[i] - _array[i - 1] < min)
            min = _array[i] - _array[i - 1];
    }
    return (min);
}

int Span::longestSpan()
{
    if (_index <= 1)
        throw std::exception();
        // throw Span::ArrayEmptyException();
    std::sort(_array.begin(), _array.end());
    return (_array[_array.size() - 1] - _array[0]);
}

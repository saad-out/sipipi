#pragma once

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int _n;
        unsigned int _index;
        std::vector<int> _array;


    public:
        Span();
        ~Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span & operator=(const Span &other);

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        // add numbers using iterators
        template <typename InputIterator>
        void addNumberRange(InputIterator begin, InputIterator end)
        {
            if (_index + std::distance(begin, end) > _n)
                throw std::exception();
                // throw Span::ArrayFullException();
            _array.insert(_array.end(), begin, end);
            _index += std::distance(begin, end);
        }

        void printArray()
        {
            for (unsigned int i = 0; i < _array.size(); i++)
                std::cout << _array[i] << " ";
            std::cout << std::endl;
        }
};

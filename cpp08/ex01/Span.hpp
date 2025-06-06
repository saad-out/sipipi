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

        // Exceptions
        class ArrayFullException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Array is full");
            }
        };

        class ArrayEmptyException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Array is empty");
            }
        };

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void printArray();

        template <typename InputIterator>
        void addNumberRange(InputIterator begin, InputIterator end)
        {
            if (_index + std::distance(begin, end) > _n)
                throw Span::ArrayFullException();
            _array.insert(_array.end(), begin, end);
            _index += std::distance(begin, end);
        }
};

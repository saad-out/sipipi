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
};

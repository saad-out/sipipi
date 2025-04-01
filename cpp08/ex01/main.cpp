#include "Span.hpp"
#include <stdlib.h>

int main()
{
    Span sp = Span(100);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    // add using iterators
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Before adding range" << std::endl;
    sp.printArray();
    sp.addNumberRange(v.begin(), v.end());
    std::cout << "After adding range" << std::endl;
    sp.printArray();

    // test with 10000 elements
    Span sp2 = Span(10000);
    for (int i = 0; i < 10000; i++)
        sp2.addNumber(rand() % 10000);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;


    return (0);
}

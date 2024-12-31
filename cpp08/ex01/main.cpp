#include "Span.hpp"

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
    std::cout << "good1" << std::endl;
    sp.addNumberRange(v.begin(), v.end());
    std::cout << "good" << std::endl;
    sp.printArray();
    std::cout << "good2" << std::endl;


    return (0);
}

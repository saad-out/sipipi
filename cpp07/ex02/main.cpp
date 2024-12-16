#include "Array.hpp"

int main()
{
    Array<int> obj(3);
    obj.print_arr();


    Array<int> obj1(0);
    obj1.print_arr();

    Array<int> obj2;
    obj2.print_arr();

    Array<int> obj3(10);
    obj3.print_arr();
    return (0);
}

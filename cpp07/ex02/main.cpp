#include "Array.hpp"

int main()
{
    Array<int> obj(3);
    std::cout << "a1 : " << obj[1] << std::endl;
    obj[1] = -1;
    std::cout << "a1 : " << obj[1] << std::endl;
    obj.print_arr();

    try
    {
        obj[-1] = -1;
        std::cout << "\n";
        obj.print_arr();
        std::cout << "\n";

    } catch (std::exception &e)
    {
        std::cout << "hi\n";
    }

    Array<int> obj1(0);
    obj1.print_arr();

    Array<int> obj2;
    obj2.print_arr();

    Array<int> obj3(10);
    obj3.print_arr();

    std::cout << "size is: " << obj3.size() << std::endl;
    return (0);
}

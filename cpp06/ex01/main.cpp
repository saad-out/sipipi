#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data;
    ptr->x = -1;

    uintptr_t addr = Serializer::serialize(ptr);
    Data *new_ptr = Serializer::deserialize(addr);

    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "new_ptr: " << new_ptr << std::endl;
    if (ptr == new_ptr)
        std::cout << "Same address ✅" << std::endl;
    else
        std::cout << "Error ❌" << std::endl;

    delete ptr;

    return (0);
}

#ifndef __SERIALIZER__
#define __SERIALIZER__

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer& operator = (const Serializer &other);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif // __SERIALIZER__

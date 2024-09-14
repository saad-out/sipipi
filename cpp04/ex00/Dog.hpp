#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog& other);
        Dog& operator = (const Dog& other);
        ~Dog(void);
        void makeSound(void) const;
};

#endif // __DOG_HPP__

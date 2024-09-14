#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat& other);
        Cat& operator = (const Cat& other);
        ~Cat(void);
        void makeSound(void) const;
};

#endif // __CAT_HPP__

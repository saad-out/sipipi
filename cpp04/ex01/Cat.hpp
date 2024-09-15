#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;

    public:
        Cat(void);
        Cat(const Cat& other);
        Cat& operator = (const Cat& other);
        ~Cat(void);
        void makeSound(void) const;
        Brain* getBrain(void) const;
};

#endif // __CAT_HPP__

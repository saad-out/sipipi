#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal& other);
        Animal& operator = (const Animal& other);
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif // __ANIMAL_HPP__

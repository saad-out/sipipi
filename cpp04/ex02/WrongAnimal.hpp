#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator = (const WrongAnimal& other);
        ~WrongAnimal(void);
        std::string getType(void) const;
        void makeSound(void) const;
};

#endif // __WRONGANIMAL_HPP__

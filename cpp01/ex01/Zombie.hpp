#ifndef __ZOMBIE__HPP__

#include <iostream>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        Zombie& operator=(const Zombie &other);
        void announce(void);
};

// protoypes
Zombie *zombieHorde(int N, std::string name);

#endif // __ZOMBIE__HPP__

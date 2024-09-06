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
        void announce(void);
};

// Prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // __ZOMBIE__HPP__

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain(void);
        Brain(const Brain& other);
        Brain& operator = (const Brain& other);
        ~Brain(void);

        /*void setChar(char c);*/
        /*void printChar(void) const;*/
};

#endif // __BRAIN_HPP__

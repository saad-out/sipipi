#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>

enum class Level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN,
};

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    
    public:
        void complain(std::string level);
};

Level str_value(std::string& str);

#endif // __HARL__HPP__

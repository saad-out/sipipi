#include <iostream>
#include "Harl.hpp"

int main(void)
{
    Harl obj;

    obj.complain("DEBUG");
    obj.complain("INFO");
    obj.complain("WARNING");
    obj.complain("HEY");
    obj.complain("ERROR");

    return (0);
}

#include <iostream>
#include "cast.hpp"
/*#include "Base.hpp"*/
/*#include "A.hpp"*/
/*#include "B.hpp"*/
/*#include "C.hpp"*/

int main()
{
    Base *b = generate();
    identify(b);
    delete b;

    A a;
    identify(a);
    B b2;
    identify(b2);
    C c;
    identify(c);

    return (0);
}

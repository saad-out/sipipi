#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
    Animal *animals[100];

    std::cout << "Creating animals" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        if (i < 50)
            animals[i]  = new Cat();
        else
            animals[i] = new Dog();
    }

    std::cout << std::endl;
    std::cout << "Deleting animals" << std::endl;
    for (int i = 0; i < 100; i++)
        delete animals[i];

    /*{*/
    /*    std::cout << "Testing copy constructor and assignement operator" << std::endl;*/
    /*    Cat c = Cat();*/
    /*    Brain *b = c.getBrain();*/
    /*    b->setChar('c');*/
    /*    Cat c2 = Cat();*/
    /*    Brain *b2 = c2.getBrain();*/
    /*    b2->setChar('b');*/
    /*    b2->printChar();*/
    /*    c2 = c;*/
    /*    Brain *b3 = c2.getBrain();*/
    /*    b3->printChar();*/
    /*    Cat c3(c2);*/
    /*    c3.getBrain()->printChar();*/
    /*}*/
    /*std::cout << std:: endl;*/
    /*{*/
    /*    std::cout << "Testing copy constructor and assignement operator" << std::endl;*/
    /*    Dog d = Dog();*/
    /*    Brain *b = d.getBrain();*/
    /*    b->setChar('c');*/
    /*    Dog c2 = Dog();*/
    /*    Brain *b2 = c2.getBrain();*/
    /*    b2->setChar('b');*/
    /*    b2->printChar();*/
    /*    c2 = d;*/
    /*    Brain *b3 = c2.getBrain();*/
    /*    b3->printChar();*/
    /*    Dog c3(c2);*/
    /*    c3.getBrain()->printChar();*/
    /**/
    /*}*/

    // The following line should not compile
    // Animal a;

    return (0);
}

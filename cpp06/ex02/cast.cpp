#include "cast.hpp"
#include <typeinfo>

Base *generate(void) {
  srand(time(NULL));
  int cls = rand() % 3;
  std::cout << "cls number: " << cls << std::endl;

  switch (cls) {
  case 0:
    return (dynamic_cast<Base *>(new A()));
  case 1:
    return (dynamic_cast<Base *>(new B()));
  default:
    return (dynamic_cast<Base *>(new C()));
  }
  return (NULL);
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (std::bad_cast &e) {
    (void)e;
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (std::bad_cast &e) {
    (void)e;
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (std::bad_cast &e) {
    (void)e;
  }
  std::cout << "Unknown" << std::endl;
  return;
}

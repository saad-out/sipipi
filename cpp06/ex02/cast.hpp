#pragma once

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

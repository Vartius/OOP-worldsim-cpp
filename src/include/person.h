#pragma once

#include "animal.h"

class person : public animal
{
public:
    person(int power, int initiative, int posX, int posY, world *w);
};
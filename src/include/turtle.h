#pragma once

#include "animal.h"

class turtle : public animal
{
public:
    turtle(int power, int initiative, int posX, int posY, world *w);
};
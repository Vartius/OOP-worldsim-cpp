#pragma once

#include "animal.h"

class sheep : public animal
{
public:
    sheep(int power, int initiative, int posX, int posY, world *w);
};
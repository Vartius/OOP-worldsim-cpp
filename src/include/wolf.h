#pragma once

#include "animal.h"

class wolf : public animal
{
public:
    wolf(int power, int initiative, int posX, int posY, world *w);
};
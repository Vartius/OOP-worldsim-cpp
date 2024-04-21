#pragma once

#include "animal.h"

class fox : public animal
{
public:
    fox(int power, int initiative, int posX, int posY, world *w);
};
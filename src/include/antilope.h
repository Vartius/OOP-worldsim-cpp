#pragma once

#include "animal.h"

class antilope : public animal
{
public:
    antilope(int power, int initiative, int posX, int posY, world *w);
};
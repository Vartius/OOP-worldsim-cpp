#pragma once

#include "plant.h"

class grass : public plant
{
public:
    grass(int power, int initiative, int posX, int posY, world *w);
};
#pragma once

#include "animal.h"

class human : public animal
{
public:
    human(int power, int initiative, int posX, int posY, world *w);
    void move();
    void behave();
};
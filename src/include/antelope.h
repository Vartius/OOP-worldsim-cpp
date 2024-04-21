#pragma once

#include "animal.h"

class antelope : public animal
{
public:
    antelope(int power, int initiative, int posX, int posY, world *w);
    void move();
    void behave();
};
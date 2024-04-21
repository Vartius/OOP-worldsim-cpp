#pragma once

#include "animal.h"

class antelope : public animal
{
public:
    antelope(int posX, int posY, world *w);
    void move();
    void behave();
};
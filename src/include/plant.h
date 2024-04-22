#pragma once

#include "entity.h"

class plant : public Entity
{
public:
    plant(int posX, int posY, world *w);
    void behave();
    void collision();
    void print();
};

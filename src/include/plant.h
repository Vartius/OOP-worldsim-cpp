#pragma once

#include "entity.h"

class plant : public Entity
{
public:
    plant(int power, int initiative, int posX, int posY, world *w);
    void behave();
    void collision();
    void print();
    void getPosition(int &x, int &y);
    void getInitiative(int &initiative);
};

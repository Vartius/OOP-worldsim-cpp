#pragma once

#include "plant.h"

class heracleum : public plant
{
public:
    heracleum(int posX, int posY, world *w);
    void behave() override;
    void attacked(Entity *attacker) override;
};
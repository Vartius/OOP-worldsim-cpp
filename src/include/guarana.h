#pragma once

#include "plant.h"

class guarana : public plant
{
public:
    guarana(int posX, int posY, world *w);
    void attacked(Entity *attacker) override;
};
#pragma once

#include "animal.h"

class human : public animal
{
public:
    human(int posX, int posY, world *w);
    void move();
    void behave() override;
    void attacked(Entity *attacker) override;
};
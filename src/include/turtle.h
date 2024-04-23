#pragma once

#include "animal.h"

class turtle : public animal
{
public:
    turtle(int posX, int posY, world *w);
    void behave() override;
    void attacked(Entity *attacker) override;
};
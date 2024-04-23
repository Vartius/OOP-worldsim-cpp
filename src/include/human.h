#pragma once

#include "animal.h"

class human : public animal
{
public:
    human(int posX, int posY, world *w);
    void move();
    void behave() override;
    void attacked(Entity *attacker) override;
    int getSpecialAbilityCooldown();
    void setSpecialAbilityCooldown(int cooldown);
private:
    int specialAbilityCooldown;
};
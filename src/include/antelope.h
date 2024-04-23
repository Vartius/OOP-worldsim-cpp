#pragma once

#include "animal.h"

class antelope : public animal
{
public:
    antelope(int posX, int posY, world *w);
    void move();
    void behave() override;
    void attacked(Entity *attacker) override;
    void collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i) override;
};
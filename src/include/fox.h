#pragma once

#include "animal.h"

class fox : public animal
{
public:
    fox(int posX, int posY, world *w);
    void behave() override;
    void collision(std::vector<Entity *> entities, std::vector<std::pair<int, int>> &moves, int i) override;
};
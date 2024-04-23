#pragma once

#include "animal.h"

class fox : public animal
{
public:
    fox(int posX, int posY, world *w);
    void behave() override;
};
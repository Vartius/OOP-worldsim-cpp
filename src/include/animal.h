#pragma once

#include "entity.h"
#include <cstdlib>

class animal : public Entity
{
public:
    animal(int posX, int posY, world *w);
    void behave();
    void collision();
    void print();
    void move();
    void reproduce(animal *otherAnimal);
    void getPosition(int &x, int &y);
    void getInitiative(int &initiative);
    void getStrength(int &strength);
    void getBirthRound(int &birthRound);
    void setPosition(int x, int y);

private:
    void createNewAnimal(int posX, int posY);
};
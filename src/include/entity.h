#pragma once

class world;

// abstract class
class Entity
{
protected:
    int power;
    int initiative;
    int posX;
    int posY;
    world *w;

public:
    Entity(int power, int initiative, int posX, int posY, world *w);
    virtual void behave() = 0;
    virtual void collision() = 0;
    virtual void print() = 0;
    virtual void getPosition(int &x, int &y) = 0;
};

#include <turtle.h>

turtle::turtle(int power, int initiative, int posX, int posY, world *w) : animal(power, initiative, posX, posY, w)
{
    power = 2;
    initiative = 1;
}
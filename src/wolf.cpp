#include <wolf.h>

wolf::wolf(int power, int initiative, int posX, int posY, world *w) : animal(power, initiative, posX, posY, w)
{
    power = 9;
    initiative = 5;
}
#include <cstdlib>
#include <dandelion.h>

dandelion::dandelion(int posX, int posY, world *w) : plant(posX, posY, w)
{
    this->symbol = 'd';
}

void dandelion::behave(){
    for (int i = 0; i < 3; i++)
    {
        if (rand() % 100 < 2)
        {
            reproduce();
        }
    }

}
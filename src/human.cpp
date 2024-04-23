#include <cstdlib>
#include <human.h>
#include <world.h>
#include <vector>
#include <ncurses.h>

human::human(int posX, int posY, world *w) : animal(posX, posY, w)
{
    this->initiative = 4;
    this->strength = 5;
    this->symbol = 'H';
}
void human::move()
{
    char c;
    bool isSet = false;
    while (!isSet)
    {
        std::vector<std::pair<int, int>> moves;
        w->cleanWorld();
        w->printWorld();
        this->w->getPossiblePoses(posX, posY, 1, moves);
        c = w->getchar();
        if (c == 'a')
        {
            for (int i = 0; i < moves.size(); i++)
            {
                if (moves[i].first == posX - 1)
                {
                    posX = moves[i].first;
                    posY = moves[i].second;
                    isSet = true;
                    break;
                }
            }
        }
        else if (c == 'd')
        {
            for (int i = 0; i < moves.size(); i++)
            {
                if (moves[i].first == posX + 1)
                {
                    posX = moves[i].first;
                    posY = moves[i].second;
                    isSet = true;
                    break;
                }
            }
        }
        else if (c == 'w')
        {
            for (int i = 0; i < moves.size(); i++)
            {
                if (moves[i].second == posY - 1)
                {
                    posX = moves[i].first;
                    posY = moves[i].second;
                    isSet = true;
                    break;
                }
            }
        }
        else if (c == 's')
        {
            for (int i = 0; i < moves.size(); i++)
            {
                if (moves[i].second == posY + 1)
                {
                    posX = moves[i].first;
                    posY = moves[i].second;
                    isSet = true;
                    break;
                }
            }
        } else if (c == 'q')
        {
            w->setGameOver(true);
            isSet = true;
        } else if (c == 'e')
        {
            if (specialAbilityCooldown == 0)
            {
                specialAbilityCooldown = 5;
                w->logf(5, "Human used special ability");
            }
        } else if (c == 'p'){
            w->saveToFile("save.txt");
            w->logf(5, "Game saved");
        }
    }
}

void human::behave()
{   
    move();
    if (specialAbilityCooldown > 0)
    {
        if (specialAbilityCooldown > 2)
        {
            move();
        } else if (rand() % 2 == 0)
        {
            move();
        }
        specialAbilityCooldown--;
    }

}

void human::attacked(Entity *attacker)
{
    if (attacker->getStrength() < 5)
    {
        return;
    }
    else
    {
        w->logf(5, "Human was attacked by %c", attacker->getSymbol());
        w->setGameOver(true);
    }
}

int human::getSpecialAbilityCooldown()
{
    return specialAbilityCooldown;
}

void human::setSpecialAbilityCooldown(int cooldown)
{
    specialAbilityCooldown = cooldown;
}
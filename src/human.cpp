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
        if (!this->w->getPossiblePoses(posX, posY, 1, moves))
        {
            w->logf(5, "No possible moves for human");
            w->getchar();
            break;
        }
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
        }
    }
}

void human::behave()
{
    move();
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
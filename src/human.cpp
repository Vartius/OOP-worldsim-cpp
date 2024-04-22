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
        if (!this->w->getPossiblePoses(posX, posY, 1, moves))
        {
            mvprintw(0, 0, "No possible moves");
            getch();
            break;
        }
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i].first == posX - 1)
                mvprintw(0, i, "a\n");
            else if (moves[i].first == posX + 1)
                mvprintw(0, i, "d\n");
            else if (moves[i].second == posY - 1)
                mvprintw(0, i, "w\n");
            else if (moves[i].second == posY + 1)
                mvprintw(0, i, "s\n");
        }
        c = getch();
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
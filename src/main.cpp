#include <cstdlib>
#include <ncurses.h>
#include <mainInclude.h>
#include <time.h>

std::vector<int> getRandPoses(int count, int width, int height)
{
    std::vector<int> poses;
    poses.push_back(0);
    poses.push_back(0);
    while (poses.size() < count)
    {
        int x = rand() % width;
        int y = rand() % height;
        bool isUnique = true;
        for (int i = 0; i < poses.size(); i += 2)
        {
            if (poses[i] == x && poses[i + 1] == y)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            poses.push_back(x);
            poses.push_back(y);
        }
    }
    return poses;
}

int main()
{
    srand(time(NULL));
    int wWidth, wHeight;
    wWidth = 20;
    wHeight = 20;
    initscr();
    world w(wWidth, wHeight);

    std::vector<int> poses = getRandPoses(40, wWidth, wHeight);
    for (int i = 0; i < poses.size(); i++)
    {
        if (i == 0)
        {
            w.addEntity(poses[i], poses[i + 1], 10);
            continue;
        }
        int animalType = rand() % 10;
        w.addEntity(poses[i], poses[i + 1], animalType);
    }

    while (!w.getGameOver())
    {
        w.sortEntities();
        w.nextEpoch();
        w.updateRound();
    }
    endwin();
    return 0;
}
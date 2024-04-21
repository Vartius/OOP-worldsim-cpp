#include <ncurses.h>
#include <mainInclude.h>

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

    std::vector<int> poses = getRandPoses(10, wWidth, wHeight);
    for (int i = 0; i < poses.size(); i++)
    {
        if (i == 0)
        {
            w.addEntity(new human(poses[i], poses[i + 1], &w));
            continue;
        }
        int animalType = rand() % 10;
        switch (animalType)
        {
        case 0:
            w.addEntity(new wolf(poses[i], poses[i + 1], &w));
            break;
        case 1:
            w.addEntity(new sheep(poses[i], poses[i + 1], &w));
            break;
        case 2:
            w.addEntity(new fox(poses[i], poses[i + 1], &w));
            break;
        case 3:
            w.addEntity(new antelope(poses[i], poses[i + 1], &w));
            break;
        case 4:
            w.addEntity(new turtle(poses[i], poses[i + 1], &w));
            break;
        case 5:
            w.addEntity(new dandelion(poses[i], poses[i + 1], &w));
            break;
        case 6:
            w.addEntity(new grass(poses[i], poses[i + 1], &w));
            break;
        case 7:
            w.addEntity(new guarana(poses[i], poses[i + 1], &w));
            break;
        case 8:
            w.addEntity(new wolfberries(poses[i], poses[i + 1], &w));
            break;
        case 9:
            w.addEntity(new heracleum(poses[i], poses[i + 1], &w));
            break;
        }
    }

    int epochs = 0;
    while (true)
    {
        clear();
        w.sortEntities();
        w.printWorld();
        w.nextEpoch();
        refresh();
        epochs++;
    }
    endwin();
    return 0;
}
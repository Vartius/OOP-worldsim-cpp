#include <human.h>
#include <world.h>
#include <cstdlib>
#include <ncurses.h>
#include <mainInclude.h>
#include <time.h>
#include <vector>

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

world* loadWorld(const char *filename)
{
    FILE *file = fopen(filename, "r");
    // world width and height and round
    int width, height, round;
    fscanf(file, "%d %d %d", &width, &height, &round);

    world *w = new world(width, height);
    w->setRound(round);

    // human specialAbilityCooldown
    int specialAbilityCooldown;
    fscanf(file, "%d", &specialAbilityCooldown);

    // number of entities
    int entitiesCount;
    fscanf(file, "%d", &entitiesCount);

    // entities
    int posX, posY, strength, birthRound, reproductionStun, stun;
    char symbol;
    for (int i = 0; i < entitiesCount; i++)
    {
        // entity type
        int type;
        fscanf(file, "%d %d %d %d %d %d %c %d %d", &posX, &posY, &strength, &birthRound, &reproductionStun, &stun, &symbol, &type, &specialAbilityCooldown);
        type = w->symbolEnum(symbol);
        if (type == 10)
        {
            w->addEntity(posX, posY, 10);
            human* ent = dynamic_cast<human*>(w->getLastEntity());
            ent->setSpecialAbilityCooldown(specialAbilityCooldown);
            ent->setBirthRound(birthRound);
            ent->setReproductionStun(reproductionStun);
            ent->setStun(stun);
            ent->setStrength(strength);
        }
        else
        {
            w->addEntity(posX, posY, type);
            Entity* ent = w->getLastEntity();
            ent->setBirthRound(birthRound);
            ent->setReproductionStun(reproductionStun);
            ent->setStun(stun);
            ent->setStrength(strength);
        }
    }

    fclose(file);
    return w;
}

int main()
{
    
    srand(time(NULL));
    initscr();
    printw("press l to load world or any key to new world\n");
    char c = getch();
    world *w = nullptr;
    if (c == 'l')
    {
        w = loadWorld("save.txt");
    }
    else 
    {
        int wWidth, wHeight;
        clear();
        printw("Enter world width: ");
        scanw("%d", &wWidth);
        printw("Enter world height: ");
        scanw("%d", &wHeight);
        w = new world(wWidth, wHeight);
        int count = wWidth * wHeight / 10;

        std::vector<int> poses = getRandPoses(count, wWidth, wHeight);
        for (int i = 0; i < poses.size(); i++)
        {
            if (i == 0)
            {
                w->logf(5, "adding human on %d %d", poses[i], poses[i + 1]);
                w->addEntity(poses[i], poses[i + 1], 10);
                continue;
            }
            int animalType = rand() % 10;
            w->logf(5, "adding %c on %d %d", w->typeEnum(animalType), poses[i], poses[i + 1]);
            w->addEntity(poses[i], poses[i + 1], animalType);
        }
    }
    while (!w->getGameOver())
    {
        w->sortEntities();
        w->nextEpoch();
        w->updateRound();
    }
    endwin();
    return 0;
}
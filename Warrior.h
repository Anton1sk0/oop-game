
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Entity.h"
#include "Position.h"

#include <string>

using namespace std;


class Warrior : public Entity // vampires and werewolfs are warriors(and warriors are entitys)
{
public:
    Warrior(string tag);
    virtual ~Warrior();

    virtual void print() = 0;
    virtual Position getRandomMove(int row, int col) = 0;

protected:
    int strength;
    int armor;
    int health;
};

#endif /* WARRIOR_H */

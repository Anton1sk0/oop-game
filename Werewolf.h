#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Entity.h"
#include "Warrior.h"
#include "Position.h"

class Werewolf : public Warrior
{
public:
    Werewolf(int strength, int armor, int health,int warriorPotion);
    virtual ~Werewolf();

    virtual void print();

    virtual Position getRandomMove(int row, int col);

private:
};

#endif /* WEREWOLF_H */

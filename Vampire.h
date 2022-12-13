#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Entity.h"
#include "Warrior.h"
#include "Position.h"

class Vampire : public Warrior
{
public:
    Vampire(int strength, int armor, int health);
    virtual ~Vampire();

    virtual void print();

    virtual Position getRandomMove(int row, int col);

private:
};

#endif /* VAMPIRE_H */


#ifndef WARRIOR_H
#define WARRIOR_H

#include "Entity.h"

class Warrior : public Entity
{
public:
    Warrior();
    virtual ~Warrior();

    virtual void print() = 0;

protected:
    int strength;
    int armor;
    int health;
};

#endif /* WARRIOR_H */

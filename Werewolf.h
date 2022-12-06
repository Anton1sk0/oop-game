#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Entity.h"
#include "Warrior.h"

class Werewolf : public Warrior
{
public:
    Werewolf();
    virtual ~Werewolf();

    virtual void print();

private:
};

#endif /* WEREWOLF_H */

#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Entity.h"
#include "Warrior.h"
#include "Position.h"

class Werewolf : public Warrior
{
public:
    Werewolf();
    virtual ~Werewolf();

    virtual void print();
    
    virtual Position getRandomMove(int row, int col);

private:
};

#endif /* WEREWOLF_H */

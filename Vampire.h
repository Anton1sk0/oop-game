#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Entity.h"
#include "Warrior.h"


class Vampire : public Warrior {
public:
    Vampire();
    virtual ~Vampire();
    
    virtual void print();
private:
    
};

#endif /* VAMPIRE_H */


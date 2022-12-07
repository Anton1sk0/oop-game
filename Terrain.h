#ifndef TERRAIN_H
#define TERRAIN_H

#include "Avatar.h"
#include "Warrior.h"
#include "Potion.h"

class Terrain // woods earth water are terrains
{
public:
    Terrain();
    virtual ~Terrain();

    virtual void display();        // checks what is inside that terrain so can then call print for it and show it
    virtual bool accessible() = 0; // accessible is virtual cause is not the same for all terrains
    virtual bool empty();          // is emtpy if accessible and warrior is nullptr and null ptr
    // just some getters-setters
    Avatar *getAvatar() const;
    void setAvatar(Avatar *avatar);
    Potion *getPotion() const;
    void setPotion(Potion *potion);
    Warrior *getWarrior() const;
    void setWarrior(Warrior *warrior);

protected:
    virtual void print() = 0; // virtual cause could be water/earth/woods
    Avatar *avatar;
    Warrior *warrior;
    Potion *potion;
};

#endif /* TERRAIN_H */

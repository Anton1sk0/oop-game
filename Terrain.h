#ifndef TERRAIN_H
#define TERRAIN_H

#include "Avatar.h"
#include "Warrior.h"
#include "Potion.h"
#include "Werewolf.h"
#include "Vampire.h"
#include "VampireAvatar.h"
#include "WerewolfAvatar.h"

class Terrain // woods earth water are terrains
{
public:
    Terrain();
    virtual ~Terrain();

    virtual void display();
    virtual bool accessible() = 0;
    virtual bool empty();
    virtual bool hasPotion();

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

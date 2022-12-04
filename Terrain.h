#ifndef TERRAIN_H
#define TERRAIN_H

#include "Avatar.h"
#include "Warrior.h"
#include "Potion.h"


class Terrain {
public:
    Terrain();
    virtual ~Terrain();
    
    virtual void display();
    virtual bool accessible() = 0;
    virtual bool empty();
    
    Avatar* getAvatar() const;
    void setAvatar(Avatar* avatar);
    Potion* getPotion() const;
    void setPotion(Potion* potion);
    Warrior* getWarrior() const ;
    void setWarrior(Warrior* warrior);

protected:
    virtual void print() = 0;
    Avatar * avatar;
    Warrior * warrior;
    Potion * potion;
};

#endif /* TERRAIN_H */

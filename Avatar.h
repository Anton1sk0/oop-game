#ifndef AVATAR_H
#define AVATAR_H

#include "Entity.h"
#include "Warrior.h"

class Avatar : public Entity {
public:
    Avatar();
    virtual ~Avatar();
   
    int getPotions() const {
        return potions;
    }
    
    bool hasPotions() {
        return potions > 0;
    }

    virtual void setPotions(int potions) {
        this->potions = potions;
    }

    virtual void increasePotions() {
        potions++;
    }

    void consumePosition() {
        if (potions > 0) {
            potions--;
        }
    }

    virtual void starthealing(){
        healed=true;
    }

    virtual void endhealing(){
        healed=false;
    }
        
    
    
    virtual void print() = 0;
    virtual void heal(Warrior * warrior, bool day) = 0;

    bool healed;

protected:
    int potions;
};

#endif /* AVATAR_H */

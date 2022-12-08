#ifndef AVATAR_H
#define AVATAR_H

#include "Entity.h"

class Avatar : public Entity
{
public:
    Avatar();
    virtual ~Avatar();

    virtual void print();

    int getPotions() const
    {
        return potions;
    }

    void setPotions(int potions)
    {
        this->potions = potions;
    }

    void increasePotions()
    {
        potions++;
    }

    void consumePosition()
    {
        if (potions > 0)
        {
            potions--;
        }
    }

private:
    int potions;
    bool group;
};

#endif /* AVATAR_H */

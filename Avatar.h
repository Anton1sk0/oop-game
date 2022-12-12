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

    virtual void setPotions(int potions)
    {
        this->potions = potions;
    }

    virtual void increasePotions()
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
    void set_group(bool group)
    {
        this->group = group;
    }

    bool get_group()
    {
        return this->group;
    }

protected:
    int potions;
    bool group;
};

#endif /* AVATAR_H */

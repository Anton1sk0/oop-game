#ifndef AVATAR_H
#define AVATAR_H

#include "Entity.h"


class Avatar : public Entity {
public:
    Avatar();
    Avatar(const Avatar& orig);
    virtual ~Avatar();
    
    virtual void print();
private:
    int potions;
};


#endif /* AVATAR_H */


#ifndef WEREWOLFAVATAR_H
#define WEREWOLFAVATAR_H
#include "Avatar.h"
#include "Entity.h"

class WerewolfAvatar : public Avatar
{
public:
    WerewolfAvatar();
    ~WerewolfAvatar();
    virtual void print();
};
#endif
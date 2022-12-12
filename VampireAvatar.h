#ifndef VAMPIREAVATAR_H
#define VAMPIREAVATAR_H
#include "Avatar.h"
#include "Entity.h"

class VampireAvatar : public Avatar
{

public:
    VampireAvatar();
    ~VampireAvatar();
    virtual void print();
};
#endif
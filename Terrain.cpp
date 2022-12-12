#include "Terrain.h"

Terrain::Terrain() : avatar(nullptr), warrior(nullptr), potion(nullptr)
{
}

Terrain::~Terrain()
{
}

bool Terrain::empty()
{
    return accessible() && warrior == nullptr && avatar == nullptr; // no woods or water, but neither other entity
}

bool Terrain::hasPotion()
{
    return potion != nullptr;
}

/*                   JUST SOME GETTERS SETTERS                    */
Avatar *Terrain::getAvatar() const
{
    return avatar;
}

void Terrain::setAvatar(Avatar *avatar)
{
    this->avatar = avatar;
}

Potion *Terrain::getPotion() const
{
    return potion;
}

void Terrain::setPotion(Potion *potion)
{
    this->potion = potion;
}

Warrior *Terrain::getWarrior() const
{
    return warrior;
}

void Terrain::setWarrior(Warrior *warrior)
{
    this->warrior = warrior;
}

void Terrain::display()
{
    if (avatar != 0)
    {
        avatar->print();
    }
    else if (warrior != 0)
    {
        warrior->print();
    }
    else if (potion != 0)
    {
        potion->print();
    }
    else
    {
        print();
    }
}
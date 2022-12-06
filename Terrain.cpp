#include "Terrain.h"

Terrain::Terrain() : avatar(0), warrior(0), potion(0)
{
}

Terrain::~Terrain()
{
}

bool Terrain::empty()
{
    return accessible() && warrior == 0 && avatar == 0; // no woods or water, but neither other entity
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
    else
    {
        print();
    }
}
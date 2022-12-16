#include "VampireAvatar.h"
#include "Warrior.h"
#include "Tags.h"

using namespace std;

VampireAvatar::VampireAvatar()
{
}

VampireAvatar::~VampireAvatar()
{
}

void VampireAvatar::print()
{
    printf("%-3s", "\033[1;33m💃\033[0m "); // problems with size of icon
}

void VampireAvatar::heal(Warrior *warrior, bool day)
{
    if (warrior->TAG == VAMPIRE_TAG && day)
    {
        warrior->setHealth(warrior->getHealth() + 1);
        this->starthealing();  
    }
}
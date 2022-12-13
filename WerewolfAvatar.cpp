#include "WerewolfAvatar.h"
#include "Tags.h"

WerewolfAvatar::WerewolfAvatar()
{
}

WerewolfAvatar::~WerewolfAvatar()
{
}

void WerewolfAvatar::print()
{
    printf("%-3s", "\033[1;33m🤺\033[0m "); // problems with size of icon
}

void WerewolfAvatar::heal(Warrior *warrior, bool day)
{
    if (warrior->TAG == WEREWOLF_TAG && !day)
    {
        warrior->setHealth(warrior->getHealth() + 1);
        this->consumePosition();
    }
}
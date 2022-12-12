#include "WerewolfAvatar.h"

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
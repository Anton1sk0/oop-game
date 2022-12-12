#include <iostream>

#include "Avatar.h"
#include "tags.h"

using namespace std;

Avatar::Avatar() : Entity(AVATAR_TAG), potions(1)
{
}

Avatar::~Avatar()
{
}

void Avatar::print()
{
    if (this->group == 0)
    {
        printf("%-3s", "\033[1;33m🤺\033[0m "); // thats print for werewolfs's team avatar
    }
    else
    {
        printf("%-3s", "\033[1;33m💃\033[0m "); // thats print for vampire's team avatar
    }
}

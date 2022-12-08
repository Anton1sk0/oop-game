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
    printf("%-3s", "\033[1;33m🤺\033[0m "); // problems with size of icon thats why -3s
}

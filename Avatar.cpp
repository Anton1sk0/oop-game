#include <iostream>

#include "Avatar.h"

using namespace std;

Avatar::Avatar()
{
}

Avatar::~Avatar()
{
}

void Avatar::print()
{

    printf("%-3s", "\033[1;33m🤺\033[0m "); // problems with size of icon
}

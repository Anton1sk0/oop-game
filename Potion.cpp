#include "Potion.h"
#include <iostream>

using namespace std;

Potion::Potion()
{
}

Potion::~Potion()
{
}

void Potion::print()
{
    printf("%-3s", "\033[1;33m🍹\033[0m ");
}
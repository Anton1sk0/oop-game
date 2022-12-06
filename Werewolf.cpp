#include <iostream>

#include "Werewolf.h"

using namespace std;

Werewolf::Werewolf()
{
}

Werewolf::~Werewolf()
{
}

void Werewolf::print()
{
    printf("%3s", "\033[1;32m🐺\033[0m ");
}

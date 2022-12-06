#include <iostream>

#include "Vampire.h"

using namespace std;

Vampire::Vampire()
{
}

Vampire::~Vampire()
{
}

void Vampire::print()
{
    printf("%3s", "\033[1;32m🧛\033[0m ");
}

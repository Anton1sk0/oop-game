#include <iostream>

#include "Woods.h"

using namespace std;

Woods::Woods()
{
}

Woods::~Woods()
{
}

void Woods::print()
{
    printf("%3s", "\033[1;32m🌲\033[0m "); // override
}

bool Woods::accessible()
{
    return false; // not accesible , avatar and warrios cant step on woods or water
}
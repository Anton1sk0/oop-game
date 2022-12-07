#include <iostream>
#include "Water.h"

using namespace std;

Water::Water()
{
}

Water::~Water()
{
}

void Water::print() // override
{
    printf("%-3s", "\033[1;32m⛲\033[0m ");
}

bool Water::accessible()
{
    return false; // not accesible , avatar and warrios cant step on woods or water
}
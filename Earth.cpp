#include <iostream>

#include "Earth.h"

using namespace std;

Earth::Earth()
{
}

Earth::~Earth()
{
}

void Earth::print()
{
    printf("%3s", ""); // override
}

bool Earth::accessible()
{
    return true; // it is accesible , avatar and warrios can step only on earth terrains
}
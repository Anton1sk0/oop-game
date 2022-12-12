#include "VampireAvatar.h"

using namespace std;
VampireAvatar::VampireAvatar()
{
}

VampireAvatar::~VampireAvatar()
{
}

void VampireAvatar::print()
{
    printf("%-3s", "\033[1;33m💃\033[0m "); // problems with size of icon
}
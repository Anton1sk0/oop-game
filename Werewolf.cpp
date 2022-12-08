#include <iostream>

#include "Werewolf.h"
#include "tags.h"

using namespace std;

Werewolf::Werewolf() : Warrior(WEREWOLF_TAG)
{
}

Werewolf::~Werewolf()
{
}

void Werewolf::print()
{
    printf("%3s", "\033[1;32m🐺\033[0m ");
}

Position Werewolf::getRandomMove(int row, int col)
{ // random move left up right or down
    int choice = rand() % 4;

    switch (choice)
    {
    case 0:
        return Position(row, col - 1);
    case 1:
        return Position(row - 1, col);
    case 2:
        return Position(row + 1, col);
    case 3:
        return Position(row, col + 1);
    default:
        return Position(row, col);
    }
}

#include <iostream>

#include "Vampire.h"
#include "tags.h"

using namespace std;

Vampire::Vampire() : Warrior(VAMPIRE_TAG)
{
}

Vampire::~Vampire()
{
}

void Vampire::print()
{
    printf("%3s", "\033[1;32m🧛\033[0m ");
}

Position Vampire::getRandomMove(int row, int col)
{
    int choice = rand() % 8;
    // random move on 8 possible directions
    switch (choice)
    {
    case 0:
        return Position(row - 1, col - 1);
    case 1:
        return Position(row, col - 1);
    case 2:
        return Position(row + 1, col - 1);
    case 3:
        return Position(row - 1, col);
    case 4:
        return Position(row + 1, col);
    case 5:
        return Position(row - 1, col + 1);
    case 6:
        return Position(row, col + 1);
    case 7:
        return Position(row + 1, col + 1);
    default:
        return Position(row, col);
    }
}

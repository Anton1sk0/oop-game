
#include <iostream>
#include <cstdlib>

#include "Game.h"

using namespace std;

int main(int argc, char **argv)
{
    int width = 20, height = 20; // map size but 20x20 for now test

    srand(time(0));

    //    cout << "Type the map width: ";
    //    cin >> width;
    //
    //    cout << "Type the map height: ";
    //    cin >> height;

    Game game(width, height); // game constructor calls map contructor to create the map

    game.create();

    game.mainLoop();

    return 0;
}

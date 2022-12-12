
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Terrain.h"

using namespace std;

int main(int argc, char **argv)
{
    int width = 5, height = 10; // map size but 10x20 for now tests
    // string species;
    // Avatar *avatar = nullptr;

    srand(time(0));

    //    cout << "Type the map width: ";
    //    cin >> width;
    //
    //    cout << "Type the map height: ";
    //    cin >> height;

    // cout << "Type your group (v for vampires or w for werewolves: ";
    // cin >> species;

    // if (species[0] == 'v')
    // {
    //     avatar = new VampireAvatar();
    // }

    // if (species[0] == 'w')
    // {
    //     avatar = new WerewolfAvatar();
    // }

    Game game(width, height); // game constructor calls map contructor to create the map

    game.create();

    game.mainLoop();

    // delete avatar;

    return 0;
}

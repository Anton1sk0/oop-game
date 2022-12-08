
#include <iostream>
#include <cstdlib>

#include "Game.h"

using namespace std;

int main(int argc, char **argv)
{
    int width = 25, height = 20; // map size but 20x20 for now tests
    string species = "v";
    Avatar * avatar = nullptr;

    srand(time(0));

    //    cout << "Type the map width: ";
    //    cin >> width;
    //
    //    cout << "Type the map height: ";
    //    cin >> height;
    
    //    cout << "Type your group (v for vampires or w for werewolves: ";
    //    cin >> species;
    
    if (species[0] == 'v') {
        avatar = new Avatar();
    }
    
    if (species[0] == 'w') {
        avatar = new Avatar();
    }

    Game game(width, height); // game constructor calls map contructor to create the map

    game.create(avatar);

    game.mainLoop();
    
    
    delete avatar;

    return 0;
}


#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Terrain.h"

using namespace std;

int main(int argc, char **argv)
{
    int width = 5, height = 10; // map size but 10x20 for now tests
    Avatar *avatar = nullptr;
    string species;

    srand(time(0));

    //    cout << "Type the map width: ";
    //    cin >> width;
    //
    //    cout << "Type the map height: ";
    //    cin >> height;

    do
    {
        cout << "Type your group (v for vampires or w for werewolves): ";
        cin >> species;

        if (species == "v")
        { // choose what side your avatar wants to be
            avatar = new VampireAvatar();
        }
        else if (species == "w")
        {
            avatar = new WerewolfAvatar();
        }
        else
        {
            cout << "Invalid choice \n";
        }
    } while (species != "v" && species != "w");

    Game game(width, height); // game constructor calls map contructor to create the map

    game.create(avatar);

    game.mainLoop();

    delete avatar;

    return 0;
}

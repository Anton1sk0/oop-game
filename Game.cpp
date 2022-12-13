#include <iostream>
#include <cstring>

#include "Game.h"
#include "Terrain.h"
#include "Tags.h"

using namespace std;

Game::Game(int width, int height) : map(width, height), day(true), running(false), move_counter(12), avatar(nullptr), quit_activated(false)
{
}

Game::~Game()
{
}

void Game::display()
{
    map.display();
}

void Game::create(Avatar *avatar)
{
    this->avatar = map.placeAvatar(avatar);
    map.placeEntities();
    map.placePotion();

    running = true;
    quit_activated = false;
}

void Game::checkItems(Terrain *terrain) // checks if there is a potion in that area and collect it if player touch
{
    if (terrain->hasPotion())
    {
        Potion *p = terrain->getPotion();
        terrain->setPotion(nullptr); // delete potion when touch it
        delete p;

        avatar->increasePotions();
    }
}

void Game::executeWarriorsActions()
{
    map.moveWarriors(); //  random move for warrior
}

void Game::executeUserAction(char action)
{
    if (action == 'w' || action == 'a' || action == 's' || action == 'd')
    { // movement
        Position &currentPosition = map.getAvatarPosition();
        unsigned int destination_row = currentPosition.row;    // takes the current row
        unsigned int destination_col = currentPosition.column; // takes the current column

        if (action == 'w') // avatar moving depends on what input user gives
        {
            destination_row--;
        }

        if (action == 's')
        {
            destination_row++;
        }

        if (action == 'a')
        {
            destination_col--;
        }

        if (action == 'd')
        {
            destination_col++;
        }

        if (destination_row >= 0 && destination_row < map.getHeight() && destination_col >= 0 && destination_col < map.getWidth()) // check if is inside the map limits
        {
            Terrain *source = map.getTerrain(currentPosition.row, currentPosition.column);
            Terrain *destination = map.getTerrain(destination_row, destination_col);

            if (destination->empty()) // if it possible to move there
            {
                destination->setAvatar(source->getAvatar()); // move the avatar and
                source->setAvatar(nullptr);                  // erase the previous avatar position on this terrain

                currentPosition.row = destination_row;    // replace the row
                currentPosition.column = destination_col; // replace the col

                checkItems(destination);

                move_counter++;

                if (move_counter % 12 == 0)
                {
                    day = !day;
                }
            }
        }
    }

    if (action == 'p')
    {
        running = false;
    }

    if (action == 'c')
    {
        running = true;
    }

    if (action == 'q')
    {
        quit_activated = true;
    }

    if (action == 'h')
    {
        if (avatar->hasPotions())
        {
            map.heal(avatar, day);
        }
    }
}

void Game::mainLoop()
{
    string action;

    while (true)
    {
        map.display();

        int v = map.count(VAMPIRE_TAG);
        int w = map.count(WEREWOLF_TAG);

        if (v == 0) // GAME ENDS WHEN VAMPIRES OR WEREWOLFS TURN TO 0
        {
            cout << "All vampires have been eliminated, \"TEAM WEREWOLF WINS\" ";
            break;
        }
        if (w == 0)
        {
            cout << "All werewolfs have been eliminated, \"TEAM VAMPIRES WINS\" ";
            break;
        }

        string note = day ? "* Day    " : " * NIGHT ";
        string am_pm = ((move_counter / 12) % 2 == 0) ? "am" : "pm";

        cout << "- Inventory potions: " << avatar->getPotions() << ", Vampires: " << v << ", Werewolves: " << w << endl;
        cout << note << (move_counter % 12) << ":00" << am_pm << "==> Type your action (w,a,s,d, p to pause or q to quit):";
        cin >> action;

        if (action != "")
        {
            executeUserAction(action[0]);

            if (quit_activated == true)
            {
                break;
            }

            if (running == true)
            {
                executeWarriorsActions();
            }
            else
            {
                cout << "Game statistics: \n";
                cout << " - total potion    = " << avatar->getPotions() << "\n";
                cout << " - total werewolfs = " << map.count(WEREWOLF_TAG) << "\n";
                cout << " - total vampires  = " << map.count(VAMPIRE_TAG) << "\n";

                do
                {
                    cout << "The game is paused, please press \"c\" to continue or \"q\" to exit game: ";
                    cin >> action;
                    executeUserAction(action[0]);
                } while (!running);
            }
        }
    }
}

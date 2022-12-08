#include <iostream>
#include <cstdlib>

#include "Map.h"
#include "Water.h"
#include "Woods.h"
#include "Earth.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Potion.h"
#include "Game.h"

using namespace std;

Map::Map(int width, int height) : loops(1000), width(width), height(height)
{
    terrain = new Terrain **[height]; // makes the first board of boards of pointers

    for (int i = 0; i < height; i++)
    {
        terrain[i] = new Terrain *[width]; // makes a board for every element of previous board
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x = rand() % 20; // genarate numbers from 0 to 19

            if (x <= 14) // 0-14 should be earth as i have seen from tests to be playable
            {
                terrain[i][j] = new Earth();
            }
            else if (x <= 17) // rest woods
            {
                terrain[i][j] = new Woods();
            }
            else
            {
                terrain[i][j] = new Water(); // and waters
            }
        }
    }
}

Map::~Map() // destructor delete the maps from new used previously
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            delete terrain[i][j]; // and terrains from new.
        }
    }
    for (int i = 0; i < height; i++)
    {
        delete[] terrain[i];
    }

    delete[] terrain;
}

void Map::display()
{
    for (int j = 0; j < width + 2; j++)
    {
        printf("%3s", "---");
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        printf("%3s", "| ");

        for (int j = 0; j < width; j++)
        {
            terrain[i][j]->display();
        }
        printf("%3s", "|\n");
    }

    for (int j = 0; j < width + 2; j++)
    {
        printf("%3s", "---");
    }
    cout << endl;

    cout << endl;
}

void Map::placeEntities() // places warriors,(vampires and werewolfs)
{
    int n = width * height / 15;
    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < loops; m++)
        {
            int i = rand() % height;
            int j = rand() % width;

            if (!terrain[i][j]->empty())
            {
                loops++;
                continue;
            }

            terrain[i][j]->setWarrior(new Vampire());
            cout << "vampire placed at: " << i << "," << j << endl;
            break;
        }

        for (int m = 0; m < loops; m++) // 'loops' is for safety
        {
            int i = rand() % height;
            int j = rand() % width;

            if (!terrain[i][j]->empty())
            {
                continue;
            }

            terrain[i][j]->setWarrior(new Werewolf());
            cout << "werewolf placed at: " << i << "," << j << endl;
            break;
        }
    }
}

Avatar *Map::placeAvatar(Avatar *avatar) // places avatar random on the map
{
    for (int k = 0; k < loops; k++) // 'loops' is for safety
    {
        int i = rand() % height;
        int j = rand() % width;

        if (!terrain[i][j]->empty()) // if is possible to place the avatar there
        {
            continue;
        }

        terrain[i][j]->setAvatar(avatar);
        cout << "Avatar placed at: " << i << "," << j << endl;

        avatarPosition.row = i; // keeps avatar position
        avatarPosition.column = j;

        return avatar; // keeps avatar
    }
}

void Map::placePotion() // place potion on the map if is possible
{
    for (int k = 0; k < loops; k++) // 'loops' is for safety
    {
        int i = rand() % height;
        int j = rand() % width;

        if (!terrain[i][j]->empty())
        {
            continue;
        }

        terrain[i][j]->setPotion(new Potion());
        cout << "Potion placed at: " << i << "," << j << endl;

        potionPosition.row = i;
        potionPosition.column = j;

        break;
    }
}

int Map::count(string tag) // counts warriors, vampires or werewolfs depends on tag
{
    int counter = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Terrain *source = terrain[i][j];
            Warrior *w = source->getWarrior();

            if (w != nullptr && w->TAG == tag)
            {
                counter++;
            }
        }
    }
    return counter;
}

void Map::moveWarriors()
{
    for (int i = 0; i < height; i++) // iterate the map
    {
        for (int j = 0; j < width; j++)
        {
            Terrain *source = terrain[i][j];
            Warrior *w = source->getWarrior();

            if (w != nullptr && rand() % 100 > 50) // 50% chance to move if there is warrior there
            {
                Position pos = w->getRandomMove(i, j);
                int destination_col = pos.column;
                int destination_row = pos.row;

                if (destination_row >= 0 && destination_row < getHeight() && destination_col >= 0 && destination_col < getWidth()) // check if it is inside map limits
                {
                    Terrain *destination = terrain[destination_row][destination_col];

                    if (destination->empty())
                    {
                        destination->setWarrior(source->getWarrior()); // move the warrior to the new position
                        source->setWarrior(nullptr);                   // delete from previous terrain
                    }
                }
            }
        }
    }
}
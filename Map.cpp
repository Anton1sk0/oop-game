#include <iostream>
#include <cstdlib>

#include "Map.h"
#include "Water.h"
#include "Woods.h"
#include "Earth.h"
#include "Vampire.h"
#include "Werewolf.h"

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

void Map::placeEntities()
{
    int n = width * height / 15; // how many entities must map has, is stadar from project instuctions
    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < loops; m++) // 'loops' is for safety
        {
            int i = rand() % height; //"random height position"
            int j = rand() % width;  //"random width position"

            if (!terrain[i][j]->empty()) // if terrain not emtpy try new i,j
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

            if (!terrain[i][j]->empty()) // if terrain is not empty try new i,j
            {
                continue;
            }

            terrain[i][j]->setWarrior(new Werewolf());
            cout << "werewolf placed at: " << i << "," << j << endl;
            break;
        }
    }
}

void Map::placeAvatar()
{
    for (int k = 0; k < loops; k++) // 'loops' is for safety
    {
        int i = rand() % height;
        int j = rand() % width;

        if (!terrain[i][j]->empty())
        {
            continue;
        }

        terrain[i][j]->setAvatar(new Avatar());
        cout << "Avatar placed at: " << i << "," << j << endl;

        avatarPosition.row = i;
        avatarPosition.column = j;

        break;
    }
}
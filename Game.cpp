#include <iostream>
#include <cstring>

#include "Game.h"

using namespace std;

Game::Game(int width, int height) : map(width, height), running(false)
{
}

Game::~Game()
{
}

void Game::display()
{
    map.display();
}

void Game::create()
{
    map.placeAvatar();   // place the avatar random on map
    map.placeEntities(); // place the entities random on map

    running = true;
}

void Game::move(char action)
{

    if (action == 'w')
    {
        Position &pos = map.getAvatarPosition();
        if (pos.row > 0)
        {
            Terrain *source = map.getTerrain(pos.row, pos.column);
            Terrain *destination = map.getTerrain(pos.row - 1, pos.column);

            if (destination->empty())
            {
                destination->setAvatar(source->getAvatar());
                source->setAvatar(nullptr);
                pos.row--;
            }
        }
    }

    if (action == 's')
    {
        Position &pos = map.getAvatarPosition();
        if (pos.row < map.getHeight() - 1)
        {
            Terrain *source = map.getTerrain(pos.row, pos.column);
            Terrain *destination = map.getTerrain(pos.row + 1, pos.column);

            if (destination->empty())
            {
                destination->setAvatar(source->getAvatar());
                source->setAvatar(nullptr);
                pos.row++;
            }
        }
    }

    if (action == 'a')
    {
        Position &pos = map.getAvatarPosition();
        if (pos.column > 0)
        {
            Terrain *source = map.getTerrain(pos.row, pos.column);
            Terrain *destination = map.getTerrain(pos.row, pos.column - 1);

            if (destination->empty())
            {
                destination->setAvatar(source->getAvatar());
                source->setAvatar(nullptr);
                pos.column--;
            }
        }
    }

    if (action == 'd')
    {
        Position &pos = map.getAvatarPosition();
        if (pos.column < map.getWidth() - 1)
        {
            Terrain *source = map.getTerrain(pos.row, pos.column);
            Terrain *destination = map.getTerrain(pos.row, pos.column + 1);

            if (destination->empty())
            {
                destination->setAvatar(source->getAvatar());
                source->setAvatar(nullptr);
                pos.column++;
            }
        }
    }
}

void Game::mainLoop()
{
    string action;

    do
    {
        map.display();

        cout << "Type your action (w,a,s,d):";
        cin >> action;

        move(action[0]);

    } while (running);
}

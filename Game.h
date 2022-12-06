#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game
{
public:
    Game(int width, int height);
    virtual ~Game();

    void create();
    void mainLoop();
    void display();

private:
    Map map;
    int total_werewolfs;
    int total_vampires;
    bool day;     // true means day , false means night
    bool running; // for future pause?

    void move(char action);
};

#endif /* GAME_H */

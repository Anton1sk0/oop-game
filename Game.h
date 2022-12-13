#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game {
public:
    Game(int width, int height);
    virtual ~Game();

    void create(Avatar * avatar);
    void mainLoop();
    void display();
    void checkItems(Terrain *terrain);

    Avatar *getAvatar() const;
    void setAvatar(Avatar *avatar);
    Potion *getPotion() const;
    void setPotion(Potion *potion);
    Warrior *getWarrior() const;
    void setWarrior(Warrior *warrior);

private:
    Map map;
    bool day; // true means day , false means night
    bool running; // for future pause?
    int move_counter;

    Avatar *avatar;
    bool quit_activated;

    void executeUserAction(char action); // executes Users Action from input
    void executeWarriorsActions(); // executes random action for warriors
};

#endif /* GAME_H */

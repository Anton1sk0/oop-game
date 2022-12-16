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

Map::Map(int width, int height) : loops(1000), width(width), height(height) {
    terrain = new Terrain **[height]; // makes the first board of boards of pointers

    for (int i = 0; i < height; i++) {
        terrain[i] = new Terrain *[width]; // makes a board for every element of previous board
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = rand() % 20; // genarate numbers from 0 to 19

            if (x <= 14) // 0-14 should be earth as i have seen from tests to be playable
            {
                terrain[i][j] = new Earth();
            } else if (x <= 17) // rest woods
            {
                terrain[i][j] = new Woods();
            } else {
                terrain[i][j] = new Water(); // and waters
            }
        }
    }
}

Map::~Map() // destructor delete the maps from new used previously
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            delete terrain[i][j]; // and terrains from new.
        }
    }
    for (int i = 0; i < height; i++) {
        delete[] terrain[i];
    }

    delete[] terrain;
}

void Map::display() {
    for (int j = 0; j < width + 2; j++) {
        printf("%3s", "---");
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        printf("%3s", "| ");

        for (int j = 0; j < width; j++) {
            terrain[i][j]->display();
        }
        printf("%3s", "|\n");
    }

    for (int j = 0; j < width + 2; j++) {
        printf("%3s", "---");
    }
    cout << endl;

    cout << endl;
}

void Map::placeEntities() // places warriors,(vampires and werewolfs)
{
    int n = width * height / 15;
    for (int k = 0; k < 2*n; k++) {
        for (int m = 0; m < loops; m++) {
            int i = rand() % height;
            int j = rand() % width;
            
            if (!terrain[i][j]->empty()) {
                loops++;
                continue;
            }
            
            int strength = rand() % 3 + 1;
            int armor = rand() % 2 + 1;
            int health = rand() % 2 + 1;
            int warriorPotion = rand()%2 +1;

            Warrior *warrior = nullptr;
            
            if (k < n) {
                warrior = new Vampire(strength, armor, health,warriorPotion);
                cout << "vampire placed at: " << i << "," << j << endl;
            } else {
                warrior = new Werewolf(strength, armor, health,warriorPotion);
                cout << "werewolf placed at: " << i << "," << j << endl;
            }
            
            terrain[i][j]->setWarrior(warrior);
            break;
        }
    }
}

Avatar *Map::placeAvatar(Avatar * avatar) // places avatar random on the map
{
    int type;

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

        if (!terrain[i][j]->empty()) {
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

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Terrain *source = terrain[i][j];
            Warrior *w = source->getWarrior();

            if (w != nullptr && w->TAG == tag) {
                counter++;
            }
        }
    }
    return counter;
}

void Map::moveWarriors() {
    for (int i = 0; i < height; i++) // iterate the map
    {
        for (int j = 0; j < width; j++) {
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

                    if (destination->empty() && (!destination->hasPotion())) {
                        destination->setWarrior(source->getWarrior()); // move the warrior to the new position
                        source->setWarrior(nullptr); // delete from previous terrain
                    }
                }
            }
        }
    }
}

void Map::heal(Avatar * avatar, bool day) // heals warriors, vampires or werewolfs depends on tag /
{

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Terrain *source = terrain[i][j];
            Warrior *w = source->getWarrior();

            if (w != nullptr) {
                avatar->heal(w, day);
            }
        }
    }
    if (avatar->healed){
        avatar->consumePosition();
        avatar->endhealing();
    }
}

void  Map::interactWarriors(){
    for (int i = 0; i < height; i++) // iterate the map
    {
        for (int j = 0; j < width; j++) {
            Terrain *source = terrain[i][j];
            Warrior *w = source->getWarrior(); //w gets the warrior in source terrain
        if (w!=nullptr){
            //////
            if (i>0){
                Terrain *above = terrain[i-1][j];
                if(Warrior *ww = above->getWarrior()){  //ww gets the warrior in above terrain
                    /////////there is a warrior in the cell above
                    if(ww!=nullptr){
                        if (w->TAG==ww->TAG){
                            if (w->getHealth()>ww->getHealth()){  //if w warrior got more life than ww warrior 
                                chainheal(w,ww);
                                 
                            }
                        }
                         else if (w->TAG != ww->TAG){
                            attack(w,ww);
                            if (ww->getHealth()<=0){
                                above->setWarrior(nullptr);
                            }
                            }
                    }
                }
            }
            if (i<height-1){
                Terrain *below=terrain[i+1][j];
                if (below->getWarrior()){
                    /////////there is a warrior in the cell below
                    if(Warrior *ww = below->getWarrior()){  //ww gets the warrior in below terrain
                    /////////there is a warrior in the cell above
                    if(ww!=nullptr){
                        if (w->TAG==ww->TAG){
                            if (w->getHealth()>ww->getHealth()){  //if w warrior got more life than ww warrior 
                                chainheal(w,ww); 
                                
                            }
                        }
                         else if (w->TAG != ww->TAG){
                            attack(w,ww);
                            if (ww->getHealth()<=0){
                                below->setWarrior(nullptr);
                            }
                            }
                    }
                }
                    
                }
            }
            if (j>0){
                Terrain *left=terrain[i][j-1]; 
                if (left->getWarrior()){
                    ////////// there is a warrior in the cell below 
                    if(Warrior *ww = left->getWarrior()){  //ww gets the warrior in left terrain
                    /////////there is a warrior in the cell above
                    if(ww!=nullptr){
                        if (w->TAG==ww->TAG){
                            if (w->getHealth()>ww->getHealth()){  //if w warrior got more life than ww warrior 
                                chainheal(w,ww);
                               
                                                 }
                              }
                              else if (w->TAG != ww->TAG){
                            attack(w,ww);
                            if (ww->getHealth()<=0){
                                left->setWarrior(nullptr);
                            }
                            }
                    }
                }
                }
            }
            if (j<width -1){
                Terrain *right = terrain[i][j+1];
                if(right->getWarrior()){
                    ////////////////there is a warrior in the cell right 
                    if(Warrior *ww = right->getWarrior()){  //ww gets the warrior in right terrain
                    /////////there is a warrior in the cell above
                    if(ww!=nullptr){
                        if (w->TAG==ww->TAG){
                            if (w->getHealth()>ww->getHealth()){  //if w warrior got more life than ww warrior 
                                chainheal(w,ww);
                               
                            }
                                 }   
                        else if (w->TAG != ww->TAG){
                            attack(w,ww);
                            if (ww->getHealth()<=0){
                                right->setWarrior(nullptr);
                            }
                        }
                    }
                }
                }
            }
        }
        }
    }
}

void Map::chainheal(Warrior * w, Warrior * ww){
        int r=rand()%3;
        if(r==0){

        }
        else if (r==1 && ww->getHealth()!=2 && w->getWarriorPotion()>0){
        w->decreaseWarriorPotion();
        ww->increaseHealth();
        }
        else if (r==2 && ww->getHealth()!=2 && w->getWarriorPotion()>1){
            w->decreaseWarriorPotion();
            ww->increaseHealth();
            w->decreaseWarriorPotion();
            ww->increaseHealth();

        }
    }

    void Map::attack(Warrior *w,Warrior *ww){
        if (w->getpower()>= ww->getpower()){
        int damage= w->getpower() - ww->getarmor();
        int currenthealth=ww->getHealth();
        int newhealth= currenthealth-damage;
        if(w->getpower()>ww->getarmor()){ //if power is less than armor so the damage is ignored
        ww->setHealth(newhealth);}
        }
    }
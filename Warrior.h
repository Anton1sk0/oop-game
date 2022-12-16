
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Entity.h"
#include "Position.h"

#include <string>

using namespace std;

class Warrior : public Entity // vampires and werewolfs are warriors(and warriors are entitys)
{
public:
    Warrior(string tag, int strength, int armor, int health,int warriorPotion);
    virtual ~Warrior();

    virtual void print() = 0;
    virtual Position getRandomMove(int row, int col) = 0;

    void setHealth(int health)
    {
        this->health = health;
    }

    int getHealth()
    {
        return this->health;
    }

    void setPower(int power)
    {
        this->strength = power;
    }

    void increaseHealth(){
        this->health++;
    }

    void decreaseHealth(){
        this->health--;
    }

    int getpower()
    {
        return this->strength;
    }

    int getarmor()
    {
        return this->armor;
    }

    void decreaseWarriorPotion(){
        warriorPotion--;
    }

    int getWarriorPotion(){
        return warriorPotion;
    }


protected:
    int strength;
    int armor;
    int health;
    int warriorPotion;
};

#endif /* WARRIOR_H */

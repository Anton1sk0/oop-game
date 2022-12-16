#include "Warrior.h"

Warrior::Warrior(string tag, int strength, int armor, int health,int warriorPotion) : Entity(tag), strength(strength), armor(armor), health(health),warriorPotion(warriorPotion) {
    
}

Warrior::~Warrior() {
}
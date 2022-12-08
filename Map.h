

#ifndef MAP_H
#define MAP_H

#include "Terrain.h"
#include "Position.h"

#include <string>

using namespace std;

class Map {
public:
    Map(int width, int height);
    virtual ~Map();

    void display();
    void placeEntities();
    Avatar * placeAvatar(Avatar * avatar);
    void placePotion();
    
    Position &getAvatarPosition() {
        return avatarPosition;
    }

    void setAvatarPosition(Position &avatarPosition) {
        this->avatarPosition = avatarPosition;
    }

    Terrain *getTerrain(int row, int column) const {
        return terrain[row][column];
    }

    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }
    
    int count(string tag);
    
    void moveWarriors();

private:
    int loops;
    int width, height;
    Terrain ***terrain;

    Position avatarPosition;
    Position potionPosition;
};

#endif /* MAP_H */

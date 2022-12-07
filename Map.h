

#ifndef MAP_H
#define MAP_H

#include "Terrain.h"
#include "Position.h"

class Map
{
public:
    Map(int width, int height);
    virtual ~Map();

    void display();
    void placeEntities();
    void placeAvatar();

    Position &getAvatarPosition()
    {
        return avatarPosition;
    }

    void setAvatarPosition(Position &avatarPosition)
    {
        this->avatarPosition = avatarPosition;
    }

    Terrain *getTerrain(int row, int column) const
    {
        return terrain[row][column];
    }

    int getHeight() const
    {
        return height;
    }

    int getWidth() const
    {
        return width;
    }

private:
    int loops;
    int width, height;
    Terrain ***terrain;

    Position avatarPosition;
};

#endif /* MAP_H */

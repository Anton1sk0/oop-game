#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity
{ // warrior and avatar are entitys
public:
    Entity(string tag);
    virtual ~Entity();

    virtual void print() = 0; // virtual cause can be warrior or avatar and 0 cause no code on cpp for print

    const string TAG;

protected:
    int row, col;
};

#endif /* ENTITY_H */

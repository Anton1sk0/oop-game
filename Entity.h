#ifndef ENTITY_H
#define ENTITY_H

class Entity
{ // warrior and avatar are entitys
public:
    Entity();
    virtual ~Entity();

    virtual void print() = 0; // virtual cause can be warrior or avatar and 0 cause no code on cpp for print

protected:
    int row, col;
};

#endif /* ENTITY_H */

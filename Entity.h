#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity();
    virtual ~Entity();
    
    virtual void print() = 0;
protected:
    int row, col;

};

#endif /* ENTITY_H */


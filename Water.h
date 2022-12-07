#ifndef WATER_H
#define WATER_H

#include "Terrain.h"

class Water : public Terrain
{
public:
    Water();
    virtual ~Water();

    virtual void print(); // override
    virtual bool accessible();

private:
};

#endif /* WATER_H */

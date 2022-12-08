#ifndef EARTH_H
#define EARTH_H

#include "Terrain.h"

class Earth : public Terrain
{
public:
    Earth();
    virtual ~Earth();

    virtual void print();      // override
    virtual bool accessible(); // accessible means there no woods or water
private:
};

#endif /* EARTH_H */

#ifndef WOODS_H
#define WOODS_H

#include "Terrain.h"


class Woods : public Terrain {
public:
    Woods();
    virtual ~Woods();
    
    virtual void print();
    virtual bool accessible();    
private:

};

#endif /* WOODS_H */


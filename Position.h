
#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int row, column;

    Position();
    Position(int row, int column);
    virtual ~Position();
};

#endif /* POSITION_H */


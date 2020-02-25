//
// Created by Luiza Negru on 2019-04-23.
//

#ifndef UNTITLED4_TRAP_H
#define UNTITLED4_TRAP_H

#include"item.h"

//Trap
#define trap -1

class Trap{

protected:
    pair<int, int>PositionTrap;

public:
    Trap(int pozx, int pozy , Map &M);

    pair<int, int>GetPositionTrap() const{
        return PositionTrap;
    }

    void functionalityTrap(Robot *rob, Map &M);

    void setPositionTrap(int row, int col)
    {
        PositionTrap.first = row;
        PositionTrap.second = col;
    }

    pair<int, int> GetPositionTrap()
    {
        return PositionTrap;
    }
};

#endif //UNTITLED4_TRAP_H

//
// Created by Luiza Negru on 2019-04-22.
//

#ifndef UNTITLED4_ROBOT_H
#define UNTITLED4_ROBOT_H

#include "map.h"

#include<vector>
class ItemMojo;
class Robot
{
protected:
    pair<int, int> PositionR;
    char compatibilityR;


public:
    Robot();
    Robot(int x, int y, char comp);
    // ~Robot();
    virtual void Move(Map &M, pair<int, int>PositionR) = 0;
    void Belvedere(Map &M);
   // virtual void Compatibility() = 0;
    pair<int, int> getPositionRobot() const {
        return PositionR;
    };

    void setPositionRobot(int moveRow, int moveColumn) {
        PositionR.first = moveRow;
        PositionR.second = moveColumn;
    }
    char GetCompatibility() const
    {
        return compatibilityR;
    }
};

class Mojo : public Robot
{
private:

public:
    Mojo();
    Mojo(int x, int y, char comp);
    void Move(Map &M, pair<int, int>PositionR);
};

class Jojo : public Robot
{
public:
    Jojo();
    Jojo(int x, int y, char comp);
    void Move(Map &M, pair<int, int>PositionR);
};

class Cojo : public Robot
{
public:
    Cojo();
    Cojo(int x, int y, char comp);
    void Move(Map &M, pair<int, int>PositionR);
};


#endif //UNTITLED4_ROBOT_H

//
// Created by Luiza Negru on 2019-04-22.
//

#ifndef UNTITLED4_ITEM_H
#define UNTITLED4_ITEM_H

#include<iostream>
#include "robot.h"


using namespace std;
class Item{

protected:
    char compatibility;
    pair <int, int> PositionItem;

public:
    Item(int pozx, int pozy, char comp, Map &M);
    pair<int, int> GetPositionItem() const{
        return PositionItem;
    }
    virtual void functionalityItem(Robot *rob, Map &M) = 0;
    char GetCompatibilityI() const {
        return compatibility;
    }


};

class ItemMojo : public Item{

public:
    ItemMojo(int pozx, int pozy, char comp, Map &M);
    void functionalityItem(Robot *rob, Map &M);
};

class ItemJojo : public Item{

public:
    ItemJojo(int pozx, int pozy, char comp, Map &M);
    void functionalityItem(Robot *rob, Map &M);
};

class ItemCojo : public Item{

public:
    ItemCojo(int pozx, int pozy, char comp, Map &M);
    void functionalityItem(Robot *rob, Map &M);
};

#endif //UNTITLED4_ITEM_H

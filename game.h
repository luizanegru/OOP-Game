//
// Created by Luiza Negru on 2019-04-22.
//

#ifndef UNTITLED4_GAME_H
#define UNTITLED4_GAME_H
#include"trap.h"

#define c 7

class Game{

    vector<Item *> items;
    //vector<Trap *> traps;
    vector<Robot *> robots;
    int numberRounds;
    int numberTraps;

public:
Game(){

    numberRounds = 0;
    numberTraps = 0;
}
Game(int x, int z) {
        numberRounds = x;
        numberTraps = z;
    }

void Initializare(Game &game, Map &map);

~Game();

void GamePlay(Game game, Map &map);
};

#endif //UNTITLED4_GAME_H

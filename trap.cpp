//
// Created by Luiza Negru on 2019-04-23.
//
#include "trap.h"
//constructor: pozitioneaza capcana pe harta
Trap::Trap(int pozx, int pozy, Map &M) {
    M.SetPosition(pozx, pozy, trap);
    PositionTrap.first = pozx;
    PositionTrap.second = pozy;
}

//aduce robotul la pozitia initiala
void Trap::functionalityTrap(Robot *rob, Map &M) {
    pair<int, int>pozR = rob->getPositionRobot();
    M.SetPosition(pozR.first, pozR.second, 0);
    M.SetPosition(0, 0, 1);
    rob->setPositionRobot(0, 0);
    pozR = rob->getPositionRobot();
}


//
// Created by Luiza Negru on 2019-04-22.
//

#include"item.h"

Item::Item(int pozx, int pozy, char comp, Map &M){

    M.SetPosition(pozx, pozy, item);
    PositionItem.first = pozx;
    PositionItem.second = pozy;
    compatibility = comp;

}

///////// Class Item for Robot Mojo ////////////

ItemMojo::ItemMojo(int pozx, int pozy, char comp, Map &M) : Item(pozx, pozy, comp, M){

}
//acest item are functionalitatea de a muta robotul cu doi pasi mai la dreapta, daca nu se poate atunci cu un pas mai in jos
void ItemMojo::functionalityItem(Robot *rob, Map &M) {

    pair<int, int>pozR = rob->getPositionRobot();
    M.SetPosition(pozR.first, pozR.second, 0);

        if( pozR.second + 2 < M.GetCols()) {
            M.SetPosition(pozR.first, pozR.second + 2, 1);
            rob->setPositionRobot(pozR.first, pozR.second + 2);
        }

            else if(pozR.first + 2 < M.GetRows())
            {
                M.SetPosition(pozR.first + 2, pozR.second, 1);
                rob->setPositionRobot(pozR.first + 2, pozR.second);
             }

                 else cout<<"Acest item NU il poate ajuta pe robot in calatoria lui!";
}

///////// Class Item for Robot Jojo ////////////
ItemJojo::ItemJojo(int pozx, int pozy, char comp, Map &M) : Item(pozx, pozy, comp, M){

}

//acest item are functionalitatea de a muta robotul un pas pe diagonala in jos
void ItemJojo::functionalityItem(Robot *rob, Map &M) {

    pair<int, int>pozR = rob->getPositionRobot();
    M.SetPosition(pozR.first, pozR.second, 0);

    if( pozR.second + 1 < M.GetCols() && pozR.first + 1 < M.GetRows()) {
        M.SetPosition(pozR.first + 1, pozR.second + 1, 1);
        rob->setPositionRobot(pozR.first + 1, pozR.second + 1);
    }
        else cout<<"Acest item NU il poate ajuta pe robot in calatoria lui!";
}

///////// Class Item for Robot Cojo ////////////

ItemCojo::ItemCojo(int pozx, int pozy, char comp, Map &M) : Item(pozx, pozy, comp, M){

}
//acest item are functionalitatea de a muta robotul in stanga sau in dreapta comorii
void ItemCojo::functionalityItem(Robot *rob, Map &M) {

    pair<int, int>pozR = rob->getPositionRobot();
    pair<int, int>pozT = M.GetTreasure();
    M.SetPosition(pozR.first, pozR.second, 0);

    if( pozT.second - 1 < M.GetCols())
    {
        M.SetPosition(pozR.first, pozT.second - 1, 1);
        rob->setPositionRobot(pozR.first, pozT.second + 1);
    }

        else if(pozT.second + 1 < M.GetCols())
        {
        M.SetPosition(pozR.first, pozT.second + 1, 1);
        rob->setPositionRobot(pozR.first, pozT.second + 1);
        }

}
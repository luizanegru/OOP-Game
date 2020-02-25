//
// Created by Luiza Negru on 2019-04-22.
//
#include"game.h"

Game::~Game()
{
    items.clear();
    robots.clear();
}

void Game::Initializare(Game &game, Map &map) {

    //int rows, cols;
    int number;
    int pozx, pozy;

    cout<<"Linia unde se afla comoara este:"<<endl;
    cin>>pozx;

    cout<<"Coloana unde se afla comoara este:"<<endl;
    cin>>pozy;

    //setam pozitia comorii;
    map.SetTreasure(pozx, pozy);

    //punem pe harta unde se afla comoara
    map.SetPosition(pozx, pozy, c);

    cout<<"Numarul de runde pe care vreti sa il joace robotul este:"<<endl;
    cin>>game.numberRounds;

    cout<<"Numarul de capcane este:"<<endl;
    cin>>game.numberTraps;

    for(number = 0; number < game.numberTraps; number++)
    {
        cout<<"Capcana "<<number<<" este pozitionata pe linia: ";
        cin>>pozx;
        cout<<" si coloana ";
        cin>>pozy;
        map.SetPosition(pozx, pozy, trap);
        cout<<endl;

    }

    robots.push_back(new Mojo(0, 0, 3));
    robots.push_back(new Jojo(0, 0, 2));
    robots.push_back(new Cojo(0, 0, 4));

    ItemMojo itm1(8, 8 , 3, map);
    ItemJojo itm2(7, 7, 2, map);
    ItemCojo itm3(10, 7, 4, map);


}

void Game::GamePlay(Game game, Map &map) {

    int numberrobot;
    cout<<"Alege robotul";
    cin>>numberrobot;

    map.SetPosition(robots[numberrobot]->getPositionRobot().first, robots[numberrobot]->getPositionRobot().second, 1);

    robots[numberrobot]->Belvedere(map);
    map.Show();
    pair<int, int>PozR;

    for(int i = 0; i < game.numberRounds; i++)
    {
        robots[numberrobot]->Move(map, PozR);
        PozR.first = robots[numberrobot]->getPositionRobot().first;
        PozR.second = robots[numberrobot]->getPositionRobot().second;
        robots[numberrobot]->setPositionRobot(PozR.first, PozR.second);
        robots[numberrobot]->Belvedere(map);
        cout<<"Runda "<<i + 1<<": "<<endl;
        map.Show();
        cout<<endl;
    }

    int numberRounds2;
    cout<<"Mai doriti sa jucati?"<<endl;
    cout<<"Introduti numarul de runde";
    cin>>numberRounds2;

    for(int i = 0; i < numberRounds2; i++)
    {
        robots[numberrobot]->Move(map, PozR);
        PozR.first = robots[numberrobot]->getPositionRobot().first;
        PozR.second = robots[numberrobot]->getPositionRobot().second;
        robots[numberrobot]->setPositionRobot(PozR.first, PozR.second);
        robots[numberrobot]->Belvedere(map);
        cout<<"Runda "<<i + game.numberRounds + 1<<": "<<endl;
        map.Show();
        cout<<endl;
    }

}
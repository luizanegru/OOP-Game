#include <iostream>

#include "robot.h"
#include"trap.h"
#include"game.h"


using namespace std;
int main()
{
   int rows, cols;
   cout<<"Numarul de linii al hartii este: "<<endl;
   cin>>rows;

    cout<<"Numarul de coloane al hartii este: "<<endl;
    cin>>cols;

    Game game;
    Map map(rows, cols);

    game.Initializare(game, map);
    game.GamePlay(game, map);



  return 0;
}

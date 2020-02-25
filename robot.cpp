//
// Created by Luiza Negru on 2019-04-22.
//


#include "robot.h"
#include "trap.h"

//contrcutor fara parametrii care seteaza variabilele la 0 si 0
Robot::Robot() {
    PositionR.first = 0;
    PositionR.second = 0;
    compatibilityR = 0;
}

//constructor cu parametrii care seteaza variabilele la o anumita pozitie
Robot::Robot(int i, int j, char comp) {
    PositionR.first = i;
    PositionR.second = j;
    compatibilityR = comp;
}

//metoda care imi marcheaza pe harta vizibilitatea robotului
void Robot::Belvedere(Map &M) {
    int i, j, mapPoz;

    for(i = 0; i < M.GetRows(); i++)
        for(j = 0; j < M.GetCols(); j++) {
            mapPoz = M.GetPosition(i, j);
            if(mapPoz == 8)
                M.SetPosition(i, j, 0);
        }

    //SETAM VALOAREA IN MATRICE -1 PATRU POZITII LA DREAPTA UNDE VEDE ROBOTELUL
    i = 1;
    while(PositionR.second + i < M.GetCols() && i  < 5 ) {
        mapPoz = M.GetPosition(PositionR.first, PositionR.second + i);
        if(mapPoz == 0 ) {
            M.SetPosition(PositionR.first, PositionR.second + i, 8);
        }
        i++;
    }
    
    //setam valoarea in matrice -1, 4 pozitii la stanga unde vede robotelul
    i = 1;
    while(PositionR.second - i  >= 0 && i  < 5 ) {
        mapPoz = M.GetPosition(PositionR.first, PositionR.second - i);
        if(mapPoz == 0 ) {
            M.SetPosition(PositionR.first, PositionR.second - i, 8);

        }
        i++;
    }
    //setam valoarea in matrice -1, 4 pozitii in sus unde vede robotelul
    i = 1;
    while(PositionR.first - i  >= 0 && i  < 5 ) {
        mapPoz = M.GetPosition(PositionR.first - i, PositionR.second);
        if(mapPoz == 0 ) {
            M.SetPosition(PositionR.first - i, PositionR.second, 8);
        }
        i++;
    }
    //setam valoarea in matrice -1, 4 pozitii in jos unde vede robotelul
    i = 1;
    while(PositionR.first + i  < M.GetRows()  && i  < 5 ) {
        mapPoz = M.GetPosition(PositionR.first + i, PositionR.second);
        if(mapPoz == 0 ) {
            M.SetPosition(PositionR.first + i, PositionR.second, 8);

        }
        i++;
    }

}

/////////MOJO///////////
Mojo::Mojo() : Robot(){ 
}
//constructor cu 2 parametrii
Mojo::Mojo(int i, int j, char comp) : Robot(i , j, comp){
}

//metoda care muta robotul Mojo pe harta - o singura mutare - in zig-zag
void Mojo::Move(Map &M, pair<int, int>PositionR) {
    int pozXR = PositionR.first;
    int pozYR = PositionR.second;

    //daca a ajuns la comoara se opreste jocul
    if(M.GetTreasure() == make_pair(pozXR, pozYR)) {
        cout<<"A gasit comoara!"<<endl;
        exit(1);
    }
        //daca va iesi din harta se va opri jocul
        else if(pozXR  == M.GetRows() && pozYR  == M.GetCols()) {
             cout<<"Robotul a pierdut!"<<endl;
        }
            else if(pozXR % 2 ==  pozYR % 2) {
                M.SetPosition(pozXR, pozYR, 0);
                pozYR++;

             }
                 else if(pozXR % 2 != pozYR % 2) {
                     M.SetPosition(pozXR, pozYR, 0);
                     pozXR++;
                 }

    //daca intalneste capcana s-a intors la pozitia initiala
    if( M.IsTrap(pozXR, pozYR) == true) {
        M.SetPosition(pozXR  , pozYR , 0);
        Trap ActiveTrap(getPositionRobot().first, getPositionRobot().second, M);
        ActiveTrap.functionalityTrap(this, M);
        pozXR = PositionR.first;
        pozYR = PositionR.second;
        cout<<"A gasit o bomba"<<endl;
    }

    //daca intalneste un item, cel compatibil cu el se va muta;
     if(M.IsItem(pozXR, pozYR) == true) {
        ItemMojo ActiveItem(getPositionRobot().first, getPositionRobot().second, GetCompatibility(), M);
            if( ActiveItem.GetCompatibilityI() == GetCompatibility()) {
                ActiveItem.functionalityItem(this, M);
                pozXR = PositionR.first;
                pozYR = PositionR.second;
            }
     }

        M.SetPosition(pozXR, pozYR, 1);
        setPositionRobot(pozXR, pozYR);
}


/////////JOJO///////////
Jojo::Jojo() : Robot(){ }

//constructor cu 2 parametrii
Jojo::Jojo(int i, int j, char comp) : Robot(i , j, comp) {

}

//metoda care misca robotul Jojo pe harta - o singura mutare - parcurge matricea coloana cu coloana
void Jojo::Move(Map &M, pair<int, int>PositionR) {
    int pozXR = PositionR.first;
    int pozYR = PositionR.second;

    if(M.GetTreasure() == make_pair(pozXR, pozYR)) {
        cout<<"A gasit comoara!"<<endl;
        exit(1);
    }

        else if(M.GetCols() % 2 == 0 && (pozXR == 0 && pozYR == M.GetCols() - 1)) {
            cout<<"Robotul a pierdut!"<<endl;
            exit(1);
         }
            else if(M.GetCols() % 2 != 0 &&(pozXR  == M.GetRows()- 1 && pozYR  == M.GetCols() - 1)) {
                 cout<<"Robotul a pierdut!"<<endl;
                 exit(1);
             }
                else if( pozXR + 1 < M.GetRows() && pozYR % 2 == 0) {
                     M.SetPosition(pozXR, pozYR, 0);
                     pozXR++;
                 }
                     else if(pozXR ==  M.GetRows() - 1 && pozYR % 2 == 0) {
                         M.SetPosition(pozXR, pozYR, 0);
                         pozYR++;
                     }
                         else if(pozXR > 0 && pozYR % 2 != 0) {
                             M.SetPosition(pozXR, pozYR, 0);
                             pozXR--;
                         }
                             else if(pozXR == 0 && pozYR % 2 != 0) {
                                 M.SetPosition(pozXR, pozYR, 0);
                                 pozYR++;
                             }

    if( M.IsTrap(pozXR, pozYR) == true) {
        M.SetPosition(pozXR  , pozYR , 0);
        Trap ActiveTrap(getPositionRobot().first, getPositionRobot().second, M);
        ActiveTrap.functionalityTrap(this, M);
        pozXR = PositionR.first;
        pozYR = PositionR.second;
        cout<<"A gasit o bomba"<<endl;
    }

    if(M.IsItem(pozXR, pozYR) == true) {
        ItemJojo ActiveItem(getPositionRobot().first, getPositionRobot().second, GetCompatibility(), M);
        if( ActiveItem.GetCompatibilityI() == GetCompatibility()) {
            M.SetPosition(pozXR, pozYR, 0);
            ActiveItem.functionalityItem(this, M);
            pozXR = PositionR.first;
            pozYR = PositionR.second;
        }
    }

    M.SetPosition(pozXR  , pozYR , 1);
    setPositionRobot(pozXR, pozYR);
}


////////COJO////////////
Cojo::Cojo() : Robot(){ }
//constructor cu 2 parametrii
Cojo::Cojo(int i, int j, char comp) : Robot(i , j, comp) {

}
//metoda care misca robotul Cojo pe harta - o singura mutare - parcurge matricea linie cu linie
void Cojo::Move(Map &M, pair<int, int>PositionR) {
    int pozXR = PositionR.first;
    int pozYR = PositionR.second;

    if(M.GetTreasure() == make_pair(pozXR, pozYR)) {
        cout<<"A gasit comoara!"<<endl;
        exit(1);
    }

    else if(pozXR == M.GetRows() - 1 && pozYR == M.GetCols() - 1) {
        cout<<"Robotul a pierdut!"<<endl;
        exit(1);
    }
    else if( pozYR + 1 < M.GetCols() && pozXR % 2 == 0) {
        M.SetPosition(pozXR, pozYR, 0);
        pozYR++;

    }
    else if(pozYR > 0 && pozXR % 2 != 0) {
        M.SetPosition(pozXR, pozYR, 0);
        pozYR--;
    }
    else if(pozYR ==  M.GetCols() - 1 && pozXR % 2 == 0) {
        M.SetPosition(pozXR, pozYR, 0);
        pozXR++;
    }
    else if(pozYR == 0 && pozXR % 2 != 0) {
        M.SetPosition(pozXR, pozYR, 0);
        pozXR++;
    }

    if( M.IsTrap(pozXR, pozYR) == true) {
        M.SetPosition(pozXR  , pozYR , 0);
        Trap ActiveTrap(getPositionRobot().first, getPositionRobot().second, M);
        ActiveTrap.functionalityTrap(this, M);
        pozXR = PositionR.first;
        pozYR = PositionR.second;
        cout<<"A gasit o bomba"<<endl;
    }
    
    if(M.IsItem(pozXR, pozYR) == true) {
        ItemCojo ActiveItem(getPositionRobot().first, getPositionRobot().second, GetCompatibility(), M);
        if( ActiveItem.GetCompatibilityI() == GetCompatibility()) {
            M.SetPosition(pozXR  , pozYR , 0);
            ActiveItem.functionalityItem(this, M);
            pozXR = PositionR.first;
            pozYR = PositionR.second;
        }
    }

    M.SetPosition(pozXR  , pozYR , 1);
    setPositionRobot(pozXR, pozYR);
}



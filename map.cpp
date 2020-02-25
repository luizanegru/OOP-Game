#include "map.h"
using namespace std;

//definim Itemul egal cu 3

//constructor cu doi parametrii
Map::Map(int r, int c) {
    rows = r;
    cols = c;
    int i;
    map = new int *[rows];

    for (i = 0; i < rows; i++) {
        map[i] = new int[cols];
    }

    for (i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = 0;
        }
    }
}

//destructor al hartii
Map::~Map() {
    for(int i = 0; i < rows; i++) {
        delete[] map[i];
    }
    delete[] map;
}

//metoda care afiseaza matricea
void Map::Show() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

bool Map::IsItem(int pozx, int pozy) const {

    if(map[pozx][pozy] == item) {
        return true;
    }

     return false;
}

bool Map::IsTrap(int pozx, int pozy) const {

    if(map[pozx][pozy] == trap) {
        return true;
    }
    
    return false;
}

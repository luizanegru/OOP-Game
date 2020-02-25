#include <iostream>
using namespace std;

#define item 3
#define trap -1

class Map {
private:
    int **map;
    int rows;
    int cols;

protected:
    pair<int, int>Treasure;

public:

    Map(int r, int c);

    ~Map();

    void Show();

    void SetPosition(int l, int c, int val) {
        map[l][c] = val;
    }

    int GetPosition(int l, int c) {
        return map[l][c];
    }

    int GetCols() {
        return cols;
    }

    int GetRows() {
        return rows;
    }

    pair<int, int> GetTreasure() {
        return Treasure;
    }

    void SetTreasure(int pozx, int pozy) {
        Treasure.first = pozx;
        Treasure.second = pozy;
    }

    bool IsTrap(int pozx, int pozy) const;
    bool IsItem(int pozx, int pozy) const;

};

#include "lifegame.h"
#include "grid.h"
#include <vector>
#include <iostream>
using namespace std;

LifeGame::LifeGame(int width, int height) :
    width{width}, height{height} {}

void LifeGame::play() {
    Grid theGrid{width, height};
    char cmd;
    int x, y;
    int N;
    while (cin >> cmd) {
        switch (cmd) {
            case 'u':
                theGrid.updateGrid();
                break;
            case 'o':
                cin >> x >> y;
                theGrid.forceAlive(x, y);
                break;
            case 'l':
                cin >> x >> y;
                theGrid.apply(x, y, 2);
                break;
            case 'a':
                cin >> x >> y;
                theGrid.apply(x, y, 3);
                break;
            case 't':
                cin >> x >> y >> N;
                theGrid.apply(x, y, 4, N);
                break;
            case 'f':
                cin >> x >> y >> N;
                theGrid.apply(x, y, 5, N);
                break;
            case 'd':
                theGrid.clearGrid();
                theGrid.init();
                while (cin >> cmd) {
                    if (cmd == 'l') {
                        theGrid.allApply(2);
                    } else if (cmd == 'a') {
                        theGrid.allApply(3);
                    } else if (cmd == 't') {
                        cin >> N;
                        theGrid.allApply(4, N);
                    } else if (cmd == 'f') {
                        cin >> N;
                        theGrid.allApply(5, N);
                    } else {
                        break;
                    }
                }
                break;
            case 'p':
                cout << theGrid;
                break;
            case 'q':
                return;
        }
    }
}
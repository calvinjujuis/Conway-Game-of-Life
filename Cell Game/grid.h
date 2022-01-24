#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include <ostream>
#include "cell.h"

class Grid {
    int width;
    int height;
    std::vector<std::vector<Cell *>> theGrid;
    std::vector<int *> periods;
    // set the number of live and dead neighbours for all cells:
    void countNeighbours();
    // increment live if (row, col) is alive:
    void checkState(int row, int col, int &live);
    void incrementPeriods();
  public:
    Grid(int w, int h);
    ~Grid();
    void init();
    void updateGrid();
    // apply rule with parameter to (x, y) in grid:
    void apply(int x, int y, int rule, int parameter = -1);
    // apply rule to all cells in grid:
    void allApply(int rule, int parameter = -1);
    // set (x, y) in grid to be alive:
    void forceAlive(int x, int y);
    void clearGrid();

    friend std::ostream &operator<<(std::ostream &out, const Grid &gridDisplay);
};

#endif
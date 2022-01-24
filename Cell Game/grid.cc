#include "grid.h"
#include "cell.h"
#include "basecell.h"
#include "decorator.h"
#include "ruleone.h"
#include "ruletwo.h"
#include "rulethree.h"
#include "rulefour.h"
#include "rulefive.h"
#include <iostream>
#include <vector>
using namespace std;

Grid::Grid(int w, int h) :
    width{w}, height{h} {
    init();
}

Grid::~Grid() {
    clearGrid();
}

void Grid::clearGrid() {
    for (auto row : theGrid) {
        for (auto col : row) {
            delete col;
        }
        row.clear();
    }
    theGrid.clear();
    for (auto period : periods) {
        delete period;
    }
    periods.clear();
}

void Grid::init() {
    clearGrid();
    for (int row = 0; row < height; ++row) {
        vector<Cell *> oneRow;
        theGrid.push_back(oneRow);
        for (int col = 0; col < width; ++col) {
            Cell *oneCell = new BaseCell{};
            theGrid[row].push_back(oneCell);
            apply(col, row, 1);
        }
    }
}

void Grid::updateGrid() {
    // update neighbours for each cell
    countNeighbours();
    // increment periods for rule four
    incrementPeriods();
    // update state for each cell and store current states in newStates
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            Cell *target = theGrid[row][col];
            target->update();
        }
    }
}

void Grid::apply(int x, int y, int rule, int parameter) {
    Cell *targetCell = theGrid[y][x];
    switch (rule) {
        case 1: 
            theGrid[y][x] = new RuleOne{targetCell};
            break;
        case 2:
            theGrid[y][x] = new RuleTwo{targetCell};
            break;
        case 3:
            theGrid[y][x] = new RuleThree{targetCell};
            break;
        case 4: {
            int *rounds = new int{0};
            periods.push_back(rounds);
            theGrid[y][x] = new RuleFour{targetCell, rounds, parameter};
            break;
        }
        case 5:
            theGrid[y][x] = new RuleFive{targetCell, parameter};
            break;
    }
}

void Grid::allApply(int rule, int parameter) {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            apply(col, row, rule, parameter);
        }
    }
}

void Grid::countNeighbours() {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            // set live and dead neighbours for each cell
            int live = 0;
            if (row - 1 >= 0) {
                checkState(row - 1, col, live);     // upper
            }
            if (row - 1 >= 0 && col - 1 >= 0) {
                checkState(row - 1, col - 1, live); // upper left
            }
            if (row - 1 >= 0 && col + 1 <= width - 1) {
                checkState(row - 1, col + 1, live); // upper right
            }
            if (col - 1 >= 0) {
                checkState(row, col - 1, live);     // left
            }
            if (col + 1 <= width - 1) {
                checkState(row, col + 1, live);     // right
            }
            if (row + 1 <= height - 1) {
                checkState(row + 1, col, live);     // lower
            }
            if (row + 1 <= height - 1 && col - 1 >= 0) {
                checkState(row + 1, col - 1, live); // lower left
            }
            if (row + 1 <= height - 1 && col + 1 <= width - 1) {
                checkState(row + 1, col + 1, live); // lower right
            }
            // update neighbours in target cell
            theGrid[row][col]->updateNeighbours(live);
        }
    }
}

void Grid::checkState(int row, int col, int &live) {
    if (theGrid[row][col]->getState()) {
        ++live;
    }
}

void Grid::forceAlive(int x, int y) {
    theGrid[y][x]->setAlive();
}

void Grid::incrementPeriods() {
    for (auto period : periods) {
        ++*period;
    }
}

ostream &operator<<(ostream &out, const Grid &gridDisplay) {
    for (int row = 0; row < gridDisplay.height; ++row) {
        for (int col = 0; col < gridDisplay.width; ++col) {
            Cell *curCell = gridDisplay.theGrid[row][col];
            if (curCell->getState()) {
                out << 'X';
            } else {
                out << '.';
            }
        }
        out << endl;
    }
    return out;
}
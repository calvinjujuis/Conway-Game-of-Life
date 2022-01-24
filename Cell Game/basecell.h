#ifndef _BASECELL_H_
#define _BASECELL_H_
#include "cell.h"
#include <vector>

class BaseCell: public Cell {
    bool state;
    int live;  // records the # of live neighbours
  public:
    BaseCell();
    void update() override;
    bool getState() override;   // returns true if alive, false if dead
    void setAlive() override;   // sets the cell to be alive
    void setDead() override;    // sets the cell to be dead
    void updateNeighbours(int live) override; // resets the number of live and dead
    int getLive() override;     // returns the number of live neighbours                
    void flip() override;       // flips state between true (alive) and false (dead)
};

#endif
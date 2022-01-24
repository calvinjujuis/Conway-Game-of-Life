#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "cell.h"

class Decorator: public Cell {
  protected:
    Cell *component;
  public:
    Decorator(Cell * component);
    virtual ~Decorator();
    bool getState() override;
    void setAlive() override;
    void setDead() override;
    void updateNeighbours(int live) override;
    int getLive() override;
    void flip() override;
};

#endif

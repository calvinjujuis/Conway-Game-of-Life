#ifndef _RULEFIVE_H_
#define _RULEFIVE_H_
#include "decorator.h"

class Cell;

class RuleFive : public Decorator {
    int friends; // record the # of friends the cell likes to have
  public:
    RuleFive(Cell *thisCell, int friends);
    void update() override;
};

#endif
#ifndef _RULEFOUR_H_
#define _RULEFOUR_H_
#include "decorator.h"

class Cell;

class RuleFour : public Decorator {
    int *rounds;    // stores the # of total rounds passed since created
    int periodLen;  // records the length of one flip period
  public:
    RuleFour(Cell *thisCell, int *rounds, int periodLen);
    void update() override;
};

#endif
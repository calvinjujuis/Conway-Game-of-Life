#ifndef _RULETHREE_H_
#define _RULETHREE_H_
#include "decorator.h"

class Cell;

class RuleThree : public Decorator {
  public:
    RuleThree(Cell *thisCell);
    void update() override;
};

#endif
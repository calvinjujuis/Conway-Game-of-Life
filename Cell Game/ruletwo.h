#ifndef _RULETWO_H_
#define _RULETWO_H_
#include "decorator.h"

class Cell;

class RuleTwo : public Decorator {
  public:
    RuleTwo(Cell *thisCell);
    void update() override;
};

#endif
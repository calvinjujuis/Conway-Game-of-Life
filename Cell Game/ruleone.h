#ifndef _RULEONE_H_
#define _RULEONE_H_
#include "decorator.h"

class Cell;

class RuleOne : public Decorator {
  public:
    RuleOne(Cell *thisCell);
    void update() override;
};

#endif
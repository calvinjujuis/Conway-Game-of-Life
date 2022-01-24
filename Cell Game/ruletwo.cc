#include "ruletwo.h"
#include "cell.h"

RuleTwo::RuleTwo(Cell *thisCell) :
    Decorator{thisCell} {}

void RuleTwo::update() {
    if (component->getLive() < 2) {
        // any cell with fewer than two living neighbours dies
        component->setDead();
    } else {
      component->update();
    }
}
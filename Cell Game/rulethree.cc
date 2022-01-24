#include "rulethree.h"
#include "cell.h"

RuleThree::RuleThree(Cell *thisCell) :
    Decorator{thisCell} {}

void RuleThree::update() {
    if (component->getLive() > 3) {
        // any cell with more than two living neighbours dies
        component->setDead();
    } else {
        component->update();
    }
}
#include "ruleone.h"
#include "cell.h"
#include <iostream>
using namespace std;

RuleOne::RuleOne(Cell *thisCell) :
    Decorator{thisCell} {}

void RuleOne::update() {
    if (component->getLive() == 3 && ! component->getState()) {
        // a dead cell with 3 live neighbours becomes alive
        component->setAlive();
    } else {
        component->update();
    }
}


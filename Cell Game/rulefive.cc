#include "rulefive.h"
#include "cell.h"

RuleFive::RuleFive(Cell *thisCell, int friends) :
    Decorator{thisCell}, friends{friends} {}

void RuleFive::update() {
    if (component->getLive() == friends) {
        component->setAlive();
    } else {
        component->update();
    }
}
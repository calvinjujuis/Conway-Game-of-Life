#include "rulefour.h"
#include "cell.h"

RuleFour::RuleFour(Cell *thisCell, int *rounds, int periodLen) :
    Decorator{thisCell}, rounds{rounds}, periodLen{periodLen} {
}

void RuleFour::update() {
    if (*rounds % periodLen == 0) {
        component->flip(); 
    } else {
        component->update();
    }
}
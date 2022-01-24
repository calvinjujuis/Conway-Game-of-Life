#include "basecell.h"
using namespace std;

BaseCell::BaseCell() :
    state{false}, live{0} {}

void BaseCell::update() {}

bool BaseCell::getState() {
    return state;
}

void BaseCell::setAlive() {
    state = true;
}

void BaseCell::setDead() {
    state = false;
}

void BaseCell::updateNeighbours(int live) {
    this->live = live;
}

void BaseCell::flip() {
    state = !state;
}

int BaseCell::getLive() {
    return live;
}
#include "cell.h"
#include "decorator.h"

Decorator::Decorator(Cell *component) 
    : component{component} {}

Decorator::~Decorator() { delete component; }

bool Decorator::getState() {
    return component->getState();
}

void Decorator::setAlive() {
    component->setAlive();
}

void Decorator::setDead() {
    component->setDead();
}

void Decorator::updateNeighbours(int live) {
    component->updateNeighbours(live);
}

int Decorator::getLive() {
    return component->getLive();
}

void Decorator::flip() {
    component->flip();
}
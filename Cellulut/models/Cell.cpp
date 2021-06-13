#include "main.h"
#include "models/Cell.h"

int Cell::getX() const { return this->x; }

int Cell::getY() const { return this->y; }

State *Cell::getState() const { return this->state; }

void Cell::setX(int _x) { this->x = _x; }

void Cell::setY(int _y) { this->y = _y; }

void Cell::setState(State *_state) { this->state = _state; }

std::string Cell::getHash() const { return std::to_string(x) + "-" + std::to_string(y); }

std::string Cell::getHashFromPos(int posX, int posY) { return std::to_string(posX) + "-" + std::to_string(posY); }

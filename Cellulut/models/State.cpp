#include "main.h"
#include "models/State.h"

State::State(unsigned int _index, std::string _label, std::string _color) : index(_index), label(_label), color(_color) {}

unsigned int State::getIndex() const { return this->index; }

std::string State::getColor() const { return this->color; }

std::string State::getLabel() const { return this->label; }

void State::setColor(std::string _color) { this->color = _color; }

void State::setLabel(std::string _label) { this->label = _label; }

QString State::getColorAsQString() const { return QString::fromUtf8(this->color.c_str()); }

QString State::getLabelAsQString() const { return QString::fromUtf8(this->label.c_str()); }

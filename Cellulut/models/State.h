#ifndef STATE_H
#define STATE_H

#include "main.h"

class State
{
protected:
    unsigned int index;
    std::string label;
    std::string color;

public:
    State(unsigned int index = 0, std::string _label = "", std::string _color = "");
    ~State() = default;

    unsigned int getIndex() const;
    std::string getLabel() const;
    std::string getColor() const;

    void setLabel(std::string _label);
    void setColor(std::string _color);

    QString getColorAsQString() const;
    QString getLabelAsQString() const;
};

#endif // STATE_H

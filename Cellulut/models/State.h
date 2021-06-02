#ifndef STATE_H
#define STATE_H

#include "main.h"

class State
{
    protected :
        string label;
        string color;
        int index;
    public :
        State(string _label = "", string _color = "", int _index = 0);
        ~State() = default;

        string getLabel() const;
        string getColor() const;
        int getIndex() const;

        void setIndex(int _index);
};

#endif // STATE_H
#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class State
{
    protected :
        string label;
        string color;
        int index;
    public :
        State() = default;
        ~State() = default;
};

#endif // STATE_H_INCLUDED

#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class State
{
    protected :
        string label;
        string color;
        int index;
    public :
        State(string _label = "", string _color = "", int _index = 0);
        ~State() = default;
};

#endif // STATE_H_INCLUDED

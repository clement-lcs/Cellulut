#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

class Cell
{
    protected :
        int x;
        int y;
        State* state;
    public :
        Cell() = default;
        ~Cell() = default;
        Cell(int X, int Y): x(X), y(Y), state(nullptr){};
};


#endif // CELL_H_INCLUDED

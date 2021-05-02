#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class Grid
{
    protected :
        unsigned int length;
        unsigned int width;
        Cell** listCells;
    public :
        Grid() = default;
        ~Grid() = default;
};


#endif // GRID_H_INCLUDED

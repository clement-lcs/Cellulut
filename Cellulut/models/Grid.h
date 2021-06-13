#ifndef GRID_H
#define GRID_H

#include "main.h"
#include "models/Cell.h"

class Grid // Singleton
{
protected:
    static Grid *singleton; // Pointer to singleton
    Grid();                 // Private constructor
    unsigned int size;
    std::map<std::string, Cell *> *mapCells;

public:
    static Grid *getGrid() noexcept { return singleton; }
    ~Grid() = default;

    unsigned int getSize() const;
    std::map<std::string, Cell *> *getCells() const;

    void setSize(unsigned int _size);
    void setCells(std::map<std::string, Cell *> *_cells);

    void removeAllCells();
    std::map<int, int> countNbCellsPerState();
};

#endif // GRID_H

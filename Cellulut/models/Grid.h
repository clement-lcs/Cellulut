#ifndef GRID_H
#define GRID_H

#include "main.h"
#include "models/Cell.h"

class Grid // Singleton
{
    protected :
        static Grid* singleton; // Pointer to singleton
        Grid(); // Private constructor
        unsigned int size;
        map<string, Cell*> *mapCells;
    public :
        static Grid* getGrid() noexcept {return singleton;}
        ~Grid() = default;

        unsigned int getSize() const {return this->size;}
        void setSize(unsigned int _size){this->size=_size;}
        map<string, Cell*>* getCells() const{return this->mapCells;}
        void setCells(map<string, Cell*>* _cells){this->mapCells = _cells;}

        void removeAllCells();
        map<int,int> countNbCellsPerState();
};


#endif // GRID_H

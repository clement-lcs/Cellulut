#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "main.h"
#include "models/Model.h"
#include "models/Grid.h"

class Automate
{
    protected :
        Model* model;
        Grid* grid;
    public :
        Automate();
        ~Automate() = default;

        Model* getModel() const;
        Grid* getGrid() const;

        void init_Grid(int width, int length);
};

#endif // AUTOMATE_H

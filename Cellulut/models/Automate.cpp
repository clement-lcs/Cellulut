#include "main.h"
#include "models/Library.h"
#include "models/Grid.h"
#include "models/Automate.h"

Automate* Automate::singleton = new Automate;

Automate::Automate()
{
    model = nullptr;
    historic = new vector<int**>;
}

void Automate::init_Grid(int size)
{
    Grid::getGrid()->setSize(size);

    for (unsigned int i=0; i < size*size; i++)
    {
        Cell *cell = new Cell(i%size, i/size);
        cell->setState(this->model->getListStates()->at(0));
        Grid::getGrid()->getCells()->insert({cell->getHash(), cell});
    }

    qInfo() << "Automate::init_Grid - grid initialized with size of "<< size;
}

State* Automate::random_state() // Return random state in listStates
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return this->getModel()->getListStates()->at(rand() % (this->getModel()->getListStates()->size()));
}

void Automate::manual_init()
{
    /*Grid::getGrid()->getlistCells()[0][0].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[0][1].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[0][2].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[0][3].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[0][4].setState(this->model->getListStates()->at(0));

    Grid::getGrid()->getlistCells()[1][0].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[1][1].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[1][2].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[1][3].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[1][4].setState(this->model->getListStates()->at(0));

    Grid::getGrid()->getlistCells()[2][0].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[2][1].setState(this->model->getListStates()->at(1));
    Grid::getGrid()->getlistCells()[2][2].setState(this->model->getListStates()->at(1));
    Grid::getGrid()->getlistCells()[2][3].setState(this->model->getListStates()->at(1));
    Grid::getGrid()->getlistCells()[2][4].setState(this->model->getListStates()->at(0));

    Grid::getGrid()->getlistCells()[3][0].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[3][1].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[3][2].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[3][3].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[3][4].setState(this->model->getListStates()->at(0));

    Grid::getGrid()->getlistCells()[4][0].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[4][1].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[4][2].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[4][3].setState(this->model->getListStates()->at(0));
    Grid::getGrid()->getlistCells()[4][4].setState(this->model->getListStates()->at(0));
*/
}


void Automate::random_init()
{
    Grid *grid=Grid::getGrid();
    int gridSize=grid->getSize();
    qInfo()<<"gridSize="<<gridSize;
    for(unsigned int posY = 0; posY < gridSize;posY++){
        for(unsigned int posX=0; posX<gridSize; posX++){
            Cell *cell = grid->getCells()->at(Cell::getHashFromPos(posX,posY));
            cell->setState(this->random_state());
        }

    }
}

unsigned int Automate::count_nearby_state(unsigned int x, unsigned int y, unsigned int state_index)
{
    unsigned int k = 0;
    for (int i=0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            if (i==1 and j==1)
                continue;
            int row = x + i - 1;
            int column = y + j - 1;
            if (row < 0)
                row = Grid::getGrid()->getSize() - 1;
            if (column < 0)
                column = Grid::getGrid()->getSize() - 1;
            if (row == Grid::getGrid()->getSize())
                row = 0;
            if (column == Grid::getGrid()->getSize())
                column = 0;
            if (Grid::getGrid()->getCells()->at(Cell::getHashFromPos(column, row))->getState()->getIndex() == state_index)
                k += 1;
        }
    }
    return k;
}

unsigned int Automate::check_rule_int(unsigned int x, unsigned int y, unsigned int rule_index)
{
    Cell *current_cell = Grid::getGrid()->getCells()->at(Cell::getHashFromPos(x,y));
    Rule_int* current_rule = this->getModel()->getRule_int()->at(rule_index);
    if (current_cell->getState()->getIndex() == current_rule->getRule_current_state())
        if (!current_rule->getRule_nb_nearby() or count_nearby_state(x,y,current_rule->getRule_state_nearby()) == current_rule->getRule_nb_nearby())
            return 1;
    return 0;
}

void Automate::next_generation()
{
    unsigned int** new_grid = new unsigned int*[Grid::getGrid()->getSize()];
    // Initialize new_grid with 0
    for (unsigned int i=0; i < Grid::getGrid()->getSize(); i++){
        new_grid[i] = new unsigned int[Grid::getGrid()->getSize()];
        for (unsigned int j=0; j < Grid::getGrid()->getSize(); j++)
            new_grid[i][j] = 0;
    }
    // Check rules for each cell
    for (unsigned int i=0; i < Grid::getGrid()->getSize(); i++){
        for (unsigned int j=0; j < Grid::getGrid()->getSize(); j++)
        {
            for(unsigned int k = 0; k < this->model->getRule_int()->size(); k++)
            {
                if (check_rule_int(i, j, k))
                    new_grid[i][j] = this->model->getRule_int()->at(k)->getRule_next_state();
            }
        }
    }
    // Put new values in Grid
    for (unsigned int i=0; i < Grid::getGrid()->getSize(); i++)
    {
        for (unsigned int j=0; j < Grid::getGrid()->getSize(); j++)
        {
            Grid::getGrid()->getCells()->at(Cell::getHashFromPos(j,i))->setState(this->model->getListStates()->at(new_grid[i][j]));
        }
    }
    return;
}

void Automate::afficher_grid()
{
    /*
    for (unsigned int i = 0; i < Grid::getGrid()->getRows(); i++){
        for (unsigned int j = 0; j < Grid::getGrid()->getColumns(); j++)
            cout<<Grid::getGrid()->getlistCells()[i][j].getState()->getLabel()<<" ";
        cout<<"\n";
    }*/
}

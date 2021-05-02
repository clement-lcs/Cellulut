#include "main.h"

Model::Model(string _name)
{
    name = _name;
    listStates = new vector<State*>;
    grid = new Grid();
    State* default_state = new State("default","white");
    //add_State(default_state);
}

string Model::getName() const{return name;}

vector<State*>* Model::getListStates() const{return listStates;}

Grid* Model::getGrid() const{return grid;}

void Model::setName(string _name){name = _name;}

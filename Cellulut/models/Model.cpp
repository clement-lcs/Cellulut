#include "main.h"
#include "models/Model.h"

Model::Model(int _id, string _title, string _description, string _author, string _dateOfCreation) : id(_id), title(_title), description(_description), author(_author), dateOfCreation(_dateOfCreation)
{
    this->listOfStates = new vector<State*>;
}

/*void Model::add_State(State* new_state)
{
    if(listStates->size() >= MAX_STATE)
    {
        //throw out_of_range("Maximum number of states reached");
    }
    for (unsigned int i =0; i < listStates->size(); i++)
    {
        if(listStates->at(i)->getIndex() == new_state->getIndex())
        {
            //throw invalid_argument("State index already exists, index : " + to_string(new_state->getIndex()));
        }
    }
    this->listStates->push_back(new_state);
    //cout<<"State added"<<endl;
    return;
}

void Model::del_State(State* _state)
{
    for(unsigned int i = 0; i < listStates->size(); i++)
    {
        if(listStates->at(i) == _state)
        {
            listStates->erase(listStates->begin()+i);
            //cout<<"State deleted"<<endl;
            return;
        }
    }
}*/


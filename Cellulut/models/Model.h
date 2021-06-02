#ifndef MODEL_H
#define MODEL_H

#include "main.h"
#include "models/State.h"

class Model
{
    protected :
        string name;
        vector<State*>* listStates;
    public :
        Model(string _name = "");
        ~Model() = default;

        string getName() const;
        vector<State*>* getListStates() const;

        void setName(string _name);

        void add_State(State* new_state);
        void del_State(State* _state);
};


#endif // MODEL_H

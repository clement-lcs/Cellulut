#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

class Model
{
    protected :
        string name;
        vector<State*>* listStates;
        Grid* grid;
    public :
        Model() = default;
        ~Model() = default;
};


#endif // MODEL_H_INCLUDED

#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

class Model
{
    protected :
        string name;
        vector<State*>* listStates;
        Grid* grid;
    public :
        Model(string _name = "");
        ~Model() = default;

        string getName() const;
        vector<State*>* getListStates() const;
        Grid* getGrid() const;

        void setName(string _name);
};


#endif // MODEL_H_INCLUDED

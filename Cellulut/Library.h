#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

class Library
{
    protected :
        vector<Model*>* listModels = new vector<Model*>;
    public :
        Library() = default;
        ~Library() = default;

        vector<Model*>* getListModels();
};


#endif // LIBRARY_H_INCLUDED

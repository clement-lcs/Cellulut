#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

class Library
{
    protected :
        static Library *singleton;  //Pointer to singleton
        Library() = default;  //Private constructor
        vector<Model*>* listModels = new vector<Model*>;
    public :
        static Library* getInstance() noexcept {return singleton;}

        ~Library() = default;
        Library(const Library&) = delete;
        Library& operator=(const Library&) = delete;

        vector<Model*>* getListModels();
};


#endif // LIBRARY_H_INCLUDED

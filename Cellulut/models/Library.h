#ifndef LIBRARY_H
#define LIBRARY_H

#include "main.h"
#include "models/Model.h"
#include "models/Surrounding.h"

class Library // Singleton
{
protected:
    static Library *singleton; // Pointer to singleton
    Library() = default;       // Private constructor
    std::vector<Surrounding *> *listSurroundings = new std::vector<Surrounding *>;
    std::vector<Model *> *listModels = new std::vector<Model *>;

public:
    static Library *getLibrary() noexcept { return singleton; }

    ~Library() = default;
    Library(const Library &) = delete;
    Library &operator=(const Library &) = delete;

    std::vector<Surrounding *> *getListSurroundings() const;
    std::vector<Model *> *getListModels() const;

    void create_Surrounding(std::string _name);
    Surrounding *get_Surrounding(unsigned int surrounding_id);
    void del_Surrounding(unsigned int surrounding_id);

    void create_Model(std::string _title, std::string _description = "", std::string _author = "", std::string _date = "");
    Model *get_Model(unsigned int model_id);
    void del_Model(unsigned int model_id);
};

#endif // LIBRARY_H

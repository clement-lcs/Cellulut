#include "main.h"
#include "models/Library.h"

Library *Library::singleton = new Library;

std::vector<Surrounding *> *Library::getListSurroundings() const { return this->listSurroundings; }

std::vector<Model *> *Library::getListModels() const { return this->listModels; }

void Library::create_Surrounding(std::string _name)
{
    Surrounding *new_surrounding = new Surrounding(this->listSurroundings->size(), _name);
    this->listSurroundings->push_back(new_surrounding);
    std::cout << "Create Surrounding '" << new_surrounding->getName() << "' with index " << new_surrounding->getId_Surrounding() << std::endl;

    /*for(unsigned int i = 0; i < listSurroundings->size(); i++)
    {
        if(listSurroundings->at(i)->getId_Surrounding() == new_surrounding->getId_Surrounding())
        {
            //throw invalid_argument("Surrounding index already exists, index : " + to_string(new_surrounding->getId_Surrounding()));
            cout<<"Surrounding index already exists"<<endl;
            return;
        }
    }
    this->listSurroundings->push_back(new_surrounding);
    cout<<"Surrounding added"<<endl;
    return;*/
}

Surrounding *Library::get_Surrounding(unsigned int surrounding_id)
{
    for (unsigned int i = 0; i < listSurroundings->size(); i++)
    {
        if (listSurroundings->at(i)->getId_Surrounding() == surrounding_id)
        {
            return listSurroundings->at(i);
        }
    }
    std::cout << "This surrounding doesn't exist";
    return nullptr;
}

void Library::del_Surrounding(unsigned int surrounding_id)
{
    /*for(unsigned int i = 0; i < listSurroundings->size(); i++)
    {
        if(listSurroundings->at(i) == _surrounding)
        {
            listSurroundings->erase(listSurroundings->begin()+i);
            cout<<"Surrounding deleted"<<endl;
            return;
        }
    }
    cout<<"This surrounding doesn't exist";
    return;*/
}

void Library::create_Model(std::string _title, std::string _description, std::string _author, std::string _date)
{
    Model *new_model = new Model(this->listModels->size(), _title, _description, _author, _date);
    this->listModels->push_back(new_model);
    std::cout << "Create Model '" << new_model->getTitle() << "' with index " << new_model->getId_Model() << std::endl;
}

Model *Library::get_Model(unsigned int model_id)
{
    if (model_id > this->listModels->size())
    {
        std::cout << "This model doesn't exists";
        return nullptr;
    }
    return this->listModels->at(model_id);
}

void Library::del_Model(unsigned int model_id)
{
    if (model_id > Library::getLibrary()->getListModels()->size() - 1)
    {
        std::cout << "This model doesn't exist" << std::endl;
    }
    else if (model_id == 0 or model_id == 1 or model_id == 2)
    {
        std::cout << "You can't delete pre-existing model" << std::endl;
    }
    else
    {
        for (unsigned int i = model_id; i < getLibrary()->getListModels()->size(); i++)
        {
            this->getListModels()->at(i)->id_model--;
        }
        std::cout << "Model '" << this->getListModels()->at(model_id)->getTitle() << "' deleted" << std::endl;
        this->listModels->erase(this->listModels->begin() + model_id);
    }
    return;
}

#include "main.h"
#include "models/Surrounding.h"
#include "models/Library.h"

Surrounding::Surrounding(unsigned int _id, std::string _name, unsigned int _radius) : id_surrounding(_id), name(_name), radius(_radius)
{
    this->id_surrounding = Library::getLibrary()->getListSurroundings()->size();
    this->interaction = new std::vector<bool>;
}

Surrounding::~Surrounding()
{
    delete[] this->interaction;
}

unsigned int Surrounding::getId_Surrounding() const { return this->id_surrounding; }

std::string Surrounding::getName() const { return this->name; }

unsigned int Surrounding::getRadius() const { return this->radius; }

std::vector<bool> *Surrounding::getInteraction() const { return this->interaction; }

void Surrounding::setName(std::string _name) { this->name = _name; }

void Surrounding::setRadius(unsigned int _radius) { this->radius = _radius; }

void Surrounding::setInteraction(std::vector<bool> *_interaction) { this->interaction = _interaction; }

void Surrounding::afficher_surround()
{
    unsigned int size = this->radius * 2 + 1;
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            if (this->interaction->at(i * size + j))
                std::cout << "True ";
            else
                std::cout << "False ";
        }
        std::cout << std::endl;
    }
}

void Surrounding::addInteraction(std::vector<bool> _interactionLine)
{
    for (unsigned int i = 0; i < _interactionLine.size(); i++)
    {
        this->interaction->push_back(_interactionLine.at(i));
    }
}

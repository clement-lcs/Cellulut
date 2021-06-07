#include "main.h"
#include "models/Surrounding.h"

Surrounding::Surrounding(string _name, unsigned int _radius): name(_name), radius(_radius)
{
    unsigned int size = this->radius * 2 + 1;
    this->interaction = new bool*[size];

    for (unsigned int i = 0; i < size; i++)
    {
        this->interaction[i] = new bool[size];
        for (unsigned int j = 0; j < size; j++)
        {
            interaction[i][j] = false;
        }
    }
}


string Surrounding::getName() const{return this->name;}

unsigned int Surrounding::getRadius() const{return this->radius;}

bool** Surrounding::getInteraction() const{return this->interaction;}


void Surrounding::setName(string _name){this->name = _name;}

void Surrounding::setRadius(unsigned int _radius){this->radius = _radius;}

void Surrounding::setInteraction(bool **_interaction){this->interaction = _interaction;}

void Surrounding::afficher_surround()
{
    for (unsigned int i = 0; i < radius*2+1; i++)
    {
        for (unsigned int j = 0; j < radius*2+1; j++)
        {
            if (interaction[i][j])
                cout<<"True ";
            else
                cout<<"False ";
        }
        cout<<endl;
    }

}

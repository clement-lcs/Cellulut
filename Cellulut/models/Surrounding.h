#ifndef SURROUNDING_H
#define SURROUNDING_H

#include "main.h"

class Surrounding
{
protected:
    unsigned int id_surrounding;
    std::string name;
    unsigned int radius;
    std::vector<bool> *interaction;
    Surrounding(unsigned int _id, std::string _name, unsigned int _radius = 1);

public:
    ~Surrounding();

    unsigned int getId_Surrounding() const;
    std::string getName() const;
    unsigned int getRadius() const;
    std::vector<bool> *getInteraction() const;

    void setName(std::string _name);
    void setRadius(unsigned int _radius);
    void setInteraction(std::vector<bool> *_interaction);

    void afficher_surround();
    void addInteraction(std::vector<bool> _interactionLine);

    friend class Library;
};

#endif // SURROUNDING_H

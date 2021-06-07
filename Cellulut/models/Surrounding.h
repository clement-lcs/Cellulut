#ifndef SURROUNDING_H
#define SURROUNDING_H

#include "main.h"

class Surrounding
{
    protected :
        string name;
        unsigned int radius;
        bool** interaction;
    public :
        Surrounding(string _name = "", unsigned int _radius = 1);
        ~Surrounding() = default;

        string getName() const;
        unsigned int getRadius() const;
        bool** getInteraction() const;

        void setName(string _name);
        void setRadius(unsigned int _radius);
        void setInteraction(bool** _interaction);

        void afficher_surround();
};


#endif // SURROUNDING_H

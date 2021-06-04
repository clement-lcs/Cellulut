#ifndef MODEL_H
#define MODEL_H

#include "main.h"
#include "models/State.h"

class Model
{
protected :
    int id;
    std::string title;
    std::string description;
    std::string author;
    std::string dateOfCreation;
    vector<State*>* listOfStates;
public :
    Model(int id, std::string title, std::string description, std::string author, std::string dateOfCreation);
    ~Model() = default;

    int getId()const{return this->id;}
    void setId(int _id){this->id=_id;}
    std::string getTitle()const{return this->title;}
    vector<State*>* getListOfStates() const{return this->listOfStates;}
    void setListOfStates(vector<State*>* _listOfStates){this->listOfStates=_listOfStates;}

    QString getTitleAsQString() const{return QString::fromUtf8(this->title.c_str());}

};


#endif // MODEL_H

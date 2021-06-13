#ifndef MODEL_H
#define MODEL_H

#include "main.h"
#include "models/Rule.h"
#include "models/State.h"
#include "models/Surrounding.h"

class Model
{
protected:
    unsigned int id_model;
    std::string title;
    std::string description;
    std::string author;
    std::string date_creation;
    std::vector<State *> *listStates;
    Surrounding *surrounding;
    std::vector<Rule_int *> *rule_int;
   std:: vector<Rule_ext *> *rule_ext;
    Model(unsigned int _id, std::string _title, std::string _description, std::string _author, std::string _date);

public:
    ~Model() = default;
    unsigned int getId_Model() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getAuthor() const;
    std::string getDate() const;
    std::vector<State *> *getListStates() const;
    Surrounding *getSurrounding() const;
    std::vector<Rule_int *> *getRule_int() const;
   std:: vector<Rule_ext *> *getRule_ext() const;

    void setTitle(std::string _title);
    void setDescription(std::string _title);
    void setAuthor(std::string _title);
    void setDate(std::string _title);
    void setListStates(std::vector<State *> *_listStates);
    void setSurrounding(Surrounding *_surrounding);
    void setRule_int(std::vector<Rule_int *> *_rule_int);
    void setRule_ext(std::vector<Rule_ext *> *_rule_ext);

    State *get_State(unsigned int _index);
    void add_State(State *new_state);
    void del_State(State *_state);

    void add_Rule_int(Rule_int *new_rule_int);
    void add_Rule_ext(Rule_ext *new_rule_ext);

    QString getTitleAsQString() const { return QString::fromStdString(this->title); }
    QString getDescriptionAsQString() const { return QString::fromStdString(this->description); }
    QString getAuthorAsQString() const { return QString::fromStdString(this->author); }
    QString getDateAsQString() const { return QString::fromStdString(this->date_creation); }

    friend class Library;
};

#endif // MODEL_H

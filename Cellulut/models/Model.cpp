#include "main.h"
#include "models/Model.h"

Model::Model(unsigned int _id_model, std::string _title, std::string _description, std::string _author, std::string _date) : id_model(_id_model), title(_title), description(_description), author(_author), date_creation(_date)
{
    this->listStates = new std::vector<State *>;
    this->surrounding = nullptr;
    this->rule_int = new std::vector<Rule_int *>;
    this->rule_ext = new std::vector<Rule_ext *>;
}

unsigned int Model::getId_Model() const { return this->id_model; }

std::string Model::getTitle() const { return this->title; }

std::string Model::getDescription() const { return this->title; }

std::string Model::getAuthor() const { return this->title; }

std::string Model::getDate() const { return this->title; }

std::vector<State *> *Model::getListStates() const { return this->listStates; }

Surrounding *Model::getSurrounding() const { return this->surrounding; }

std::vector<Rule_int *> *Model::getRule_int() const { return this->rule_int; }

std::vector<Rule_ext *> *Model::getRule_ext() const { return this->rule_ext; }

void Model::setTitle(std::string _title) { this->title = _title; }

void Model::setDescription(std::string _description) { this->description = _description; }

void Model::setAuthor(std::string _author) { this->author = _author; }

void Model::setDate(std::string _date) { this->date_creation = _date; }

void Model::setListStates(std::vector<State *> *_listStates) { this->listStates = _listStates; }

void Model::setSurrounding(Surrounding *_surrounding) { this->surrounding = _surrounding; }

void Model::setRule_int(std::vector<Rule_int *> *_rule_int) { this->rule_int = _rule_int; }

void Model::setRule_ext(std::vector<Rule_ext *> *_rule_ext) { this->rule_ext = _rule_ext; }

State *Model::get_State(unsigned int _index)
{
    for (unsigned int i = 0; i < listStates->size(); i++)
    {
        if (listStates->at(i)->getIndex() == _index)
        {
            return listStates->at(i);
        }
    }
    std::cout << "This state index doesn't exist" << std::endl;
    return nullptr;
}

void Model::add_State(State *new_state)
{
    if (listStates->size() >= MAX_STATE)
    {
        //throw out_of_range("Maximum number of states reached");
    }
    for (unsigned int i = 0; i < listStates->size(); i++)
    {
        if (listStates->at(i)->getIndex() == new_state->getIndex())
        {
            //throw invalid_argument("State index already exists, index : " + to_string(new_state->getIndex()));
            std::cout << "State index already exists" << std::endl;
            return;
        }
    }
    this->listStates->push_back(new_state);
    std::cout << "State '" << new_state->getLabel() << "' added to '" << this->getTitle() << "'" << std::endl;
    return;
}

void Model::del_State(State *_state)
{
    if (this->listStates->size() == 1)
    {
        std::cout << "At least 1 state needed" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < listStates->size(); i++)
    {
        if (listStates->at(i) == _state)
        {
            listStates->erase(listStates->begin() + i);
            std::cout << "State '" << _state->getLabel() << "' deleted" << std::endl;
            return;
        }
    }
    std::cout << "This state doesn't exist";
    return;
}

void Model::add_Rule_int(Rule_int *new_rule_int)
{
    this->rule_int->push_back(new_rule_int);
    return;
}

void Model::add_Rule_ext(Rule_ext *new_rule_ext)
{
    this->rule_ext->push_back(new_rule_ext);
    return;
}

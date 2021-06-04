#ifndef STATE_H
#define STATE_H

#include "main.h"

class State
{
protected :
    int index;
    std::string color;
    std::string label;
public :
    State(int index,  std::string color,  std::string label);
    ~State() = default;

    int getIndex() const {return this->index;}
    void setIndex(int _index){this->index=_index;}
    std::string getColor() const{return this->color;}
    void setColor(std::string _color){this->color = _color;}
    std::string getLabel() const{return this->label;}
    void setLabel(std::string _label){this->label=_label;}

    QString getColorAsQString() const{return QString::fromUtf8(this->color.c_str());}
    QString getLabelAsQString() const{return QString::fromUtf8(this->label.c_str());}
};

#endif // STATE_H

#ifndef STATESDISPLAY_H
#define STATESDISPLAY_H

#include "main.h"
#include "models/State.h"
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLCDNumber>

class StatesDisplay : public QWidget
{
    Q_OBJECT
public:
    StatesDisplay(QWidget *parent = nullptr, vector<State*> *listOfStates= nullptr);
    ~StatesDisplay();
private:
    QGridLayout *layout;

    map<int, QWidget*> *mapOfColors;
    map<int, QLabel*> *mapOfLabels;
    map<int, QLCDNumber*> *mapOfCounts;
};

#endif // STATESDISPLAY_H

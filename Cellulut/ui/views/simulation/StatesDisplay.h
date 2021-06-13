#ifndef STATESDISPLAY_H
#define STATESDISPLAY_H

#include "main.h"
#include "models/State.h"
#include "models/Automate.h"
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLCDNumber>

class StatesDisplay : public QWidget
{
    Q_OBJECT
public:
    StatesDisplay(QWidget *parent = nullptr);
    ~StatesDisplay();

public slots:
    void refreshCounters();

private:
    QGridLayout *layout;

    std::map<int, QWidget*> *mapOfColors;
    std::map<int, QLabel*> *mapOfLabels;
    std::map<int, QLCDNumber*> *mapOfCounts;
};

#endif // STATESDISPLAY_H

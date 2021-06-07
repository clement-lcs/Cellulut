#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QWidget>
#include "ui/UIEngine.h"

namespace Ui {
class SimulationView;
}

class UIEngine;

class SimulationView : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationView(QWidget *parent = nullptr, UIEngine *uiEngine = 0);
    ~SimulationView();

private:
    Ui::SimulationView *ui;
    UIEngine *uiEngine;
};

#endif // SIMULATIONVIEW_H

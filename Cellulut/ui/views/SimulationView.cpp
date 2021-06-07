#include "SimulationView.h"
#include "ui_SimulationView.h"

SimulationView::SimulationView(QWidget *parent, UIEngine *_uiEngine) :
    QWidget(parent),
    ui(new Ui::SimulationView),
    uiEngine(_uiEngine)
{
    ui->setupUi(this);
    qInfo() << "SimulationView::SimulationView - constructor";
}

SimulationView::~SimulationView()
{
    delete ui;
    qInfo() << "SimulationView::~SimulationView - destructor";
}

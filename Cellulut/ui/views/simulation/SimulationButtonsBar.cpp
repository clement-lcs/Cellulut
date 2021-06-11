#include "SimulationButtonsBar.h"

SimulationButtonsBar::SimulationButtonsBar(QWidget *_parent) : QWidget(_parent)
{
    this->setObjectName("simulationButtonsBar");

    this->stopButton = new QPushButton;
    this->stopButton->setIcon(QIcon(":/icons/stop.svg"));
    this->stopButton->setDisabled(true);
    this->stopButton->setToolTip("Réinitialiser la simulation");
    this->startButton = new QPushButton;
    this->startButton->setIcon(QIcon(":/icons/play.svg"));
    this->startButton->setDisabled(false);
    this->startButton->setToolTip("Lancer la simulation");
    this->stepForwardButton = new QPushButton;
    this->stepForwardButton->setIcon(QIcon(":/icons/step-forward.svg"));
    this->stepForwardButton->setToolTip("Pas à pas");
    this->stepForwardButton->setDisabled(false);

    this->hboxLayout = new QHBoxLayout();
    this->hboxLayout->addWidget(this->stopButton);
    this->hboxLayout->addWidget(this->startButton);
    this->hboxLayout->addWidget(this->stepForwardButton);

    this->setLayout(this->hboxLayout);

    connect(this->stepForwardButton, &QPushButton::clicked, this, &SimulationButtonsBar::stepForward);
    connect(this->startButton, &QPushButton::clicked, this, &SimulationButtonsBar::start);
    connect(this->stopButton, &QPushButton::clicked, this, &SimulationButtonsBar::stop);

    qInfo() << "SimulationButtonsBar::SimulationButtonsBar - constructor";
}

SimulationButtonsBar::~SimulationButtonsBar(){
    delete this->hboxLayout;

    qInfo() << "SimulationButtonsBar::~SimulationButtonsBar - destructor";
}

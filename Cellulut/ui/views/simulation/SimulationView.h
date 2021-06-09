#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QCoreApplication>
#include <QSlider>
#include <QLineEdit>
#include <QSizePolicy>
#include "models/Model.h"
#include "SimulationBoard.h"
#include "StatesDisplay.h"

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class SimulationBoard;

class SimulationView : public QWidget
{
    Q_OBJECT
public:
    SimulationView(QWidget *parent = nullptr);
    ~SimulationView();
private:
    SimulationBoard *board;
    Model *modelForSimulation;

    QLabel *modelTitle;
    QLabel *modelDescription;
    QLabel *modelAuthor;
    QLabel *modelDate;

    QPushButton *startButton;
    QLineEdit *inputSize;
    QSlider *sliderSize;
    QWidget *sizeDisplay;
    StatesDisplay *statesDisplay;

    QGridLayout *gridLayout;

    QLabel *createLabel(const QString &text, const QString &objectName, int fontSize, bool isBold, bool isItalic);

    void setupGridLayout();
    void setupLabelsForModel();
    void initEvents();
    void updateInputSizeValueFromInt(int newValue);
    void updateInputSizeValueFromString(QString newValue);

    const char *styleSheet =
            "";
};

#endif // SIMULATIONVIEW_H

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
#include "ui/views/grid/SimulationBoard.h"

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
    QLabel *createLabel(const QString &text);

    SimulationBoard *board;
    QLabel *displayMessage;
    QPushButton *startButton;
    QLineEdit *inputSize;
    QSlider *sliderSize;

    void initEvents();
    void updateInputSizeValueFromInt(int newValue);
    void updateInputSizeValueFromString(QString newValue);
};

#endif // SIMULATIONVIEW_H

#ifndef SIMULATIONBOARD_H
#define SIMULATIONBOARD_H

#include "main.h"
#include "models/Cell.h"
#include "models/State.h"
#include <QObject>
#include <QFrame>
#include <QPaintEvent>
#include <QPainter>
#include <QRgb>

class SimulationBoard : public QFrame
{
    Q_OBJECT;
public:
    SimulationBoard(QWidget *parent = nullptr, vector<State*> *listOfStates = nullptr);
    ~SimulationBoard();
public slots:
    void changeGridSize(int newValue);
protected:
    void paintEvent(QPaintEvent *pe) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    int gridSize;
    bool isInConfigurationMode;
    int squareSize(){return contentsRect().width() / gridSize;}
    void drawSquare(QPainter &painter, int x, int y, QString colorAsString);
    void clearBoard();
    map<string, Cell*> *board = 0;
    vector<State*> *listOfStates = 0;
};
#endif // SIMULATIONBOARD_H

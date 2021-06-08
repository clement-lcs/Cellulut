#include "SimulationBoard.h"

SimulationBoard::SimulationBoard(QWidget *parent) : QFrame(parent)
{
    this->boardHeight = MIN_GRID_SIZE;
    this->boardWidth = MIN_GRID_SIZE;
    setFrameStyle(QFrame::Panel|QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    clearBoard();
}

void SimulationBoard::changeGridSize(int newValue){
    if(newValue %2 != 0){
        this->boardHeight = newValue;
        this->boardWidth = newValue;
        update();
        emit gridSizeChanged(newValue);
    }
}

void SimulationBoard::clearBoard(){
    qInfo() << "SimulationBoard::clearBoard";
}

void SimulationBoard::paintEvent(QPaintEvent *event){
    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect rect=contentsRect();

    int boardTop = rect.bottom() - boardHeight*squareHeight();

    for(unsigned int i=0; i < boardHeight; ++i){
        for(unsigned int j = 0; j < boardWidth; ++j){
            drawSquare(painter, rect.left() + j * squareWidth(),
                       boardTop + i * squareHeight());
        }
    }
}

void SimulationBoard::drawSquare(QPainter &painter, int x, int y){
    QColor color(0xFFFFFF);

    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
                     color);

    painter.setPen(color.lighter());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    painter.setPen(color.darker());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidth() - 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + 1);
}

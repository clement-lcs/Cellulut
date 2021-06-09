#include "SimulationBoard.h"

SimulationBoard::SimulationBoard(QWidget *parent) : QFrame(parent)
{
    qInfo() << "SimulationBoard::SimulationBoard - constructor";
    this->gridSize = MIN_GRID_SIZE;

    this->listOfStates = new vector<State*>();
    this->listOfStates->push_back(new State(0, "VIVANT","#FFFFFF"));
    this->listOfStates->push_back(new State(1, "MORT","#000000"));
    this->listOfStates->push_back(new State(2, "EN PHASE DE DECES","#FF0000"));
    this->listOfStates->push_back(new State(3, "EN PHASE DE NAISSANCE","#00FF00"));

    this->board = new map<string,Cell*>();

    setFrameStyle(QFrame::Panel|QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    isInConfigurationMode=true;

    clearBoard();
}

SimulationBoard::~SimulationBoard()
{
    qInfo() << "SimulationBoard::SimulationBoard - destructor BEGIN";

    delete [] this->board;

    qInfo() << "SimulationBoard::~SimulationBoard - destructor END";
}


void SimulationBoard::changeGridSize(int newValue){
    this->gridSize = newValue;
    clearBoard();
    update();
}

void SimulationBoard::clearBoard(){
    map<string,Cell*>::iterator it;
    for(map<std::string, Cell*>::iterator itr = this->board->begin(); itr != this->board->end(); itr++)
    {
        delete (itr->second);
    }
    this->board->clear();
    int i;
    for(i =0; i < this->gridSize * this->gridSize; i++){
        Cell *cell = new Cell(i%gridSize,i/gridSize);
        cell->setState(this->listOfStates->at(0));
        this->board->insert({cell->getHash(), cell});
    }
}

void SimulationBoard::paintEvent(QPaintEvent *event){
    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect rect=contentsRect();

    int boardTop = rect.bottom() - gridSize*squareSize();

    for(unsigned int i=0; i < this->board->size(); i++){
        int cellX = i%gridSize;
        int cellY = i/gridSize;
        Cell *cell = this->board->at(Cell::getHashFromPos(cellX, cellY));
        QString color = QString::fromStdString(cell->getState()->getColor());
        drawSquare(painter, rect.left() + cellX * squareSize(),
                   boardTop + cellY * squareSize(), color);
    }
}

void SimulationBoard::mousePressEvent(QMouseEvent *event){

    if(!isInConfigurationMode){
        qInfo() << "SimulationBoard::mousePressEvent - not in configuration mode, ignore click event";
        return;
    }

    int clickPosX = event->pos().x();
    int clickPosY = event->pos().y();

    // Check if click is not outside the grid
    int gridMaxXorY = this->squareSize()*this->gridSize;
    int gridMinY = contentsRect().bottom() - gridSize*squareSize();

    if(clickPosX > gridMaxXorY || clickPosY > gridMinY+gridMaxXorY || clickPosY < gridMinY){
        qInfo() << "SimulationBoard::mousePressEvent - click outside of the grid, ignore click event";
        return;
    }

    // Get clicked cell hash
    int cellX = clickPosX / this->squareSize();
    int cellY= (clickPosY-gridMinY) / this->squareSize();
    string cellHash = Cell::getHashFromPos(cellX, cellY);

    // Change cell state
    Cell *cell = this->board->at(cellHash);
    State *state = cell->getState();
    int stateIndex = state->getIndex();
    int nextStateIndex = stateIndex + 1 < listOfStates->size() ? stateIndex+1 : 0;
    cell->setState(this->listOfStates->at(nextStateIndex));
    update();
}

void SimulationBoard::drawSquare(QPainter &painter, int x, int y, QString colorAsString){
    QColor color(colorAsString);
    painter.fillRect(x + 1, y + 1, squareSize() - 2, squareSize() - 2,
                     color);
    painter.setPen(color.lighter());
    painter.drawLine(x, y + squareSize() - 1, x, y);
    painter.drawLine(x, y, x + squareSize() - 1, y);

    painter.setPen(color.darker());
    painter.drawLine(x + 1, y + squareSize() - 1,
                     x + squareSize() - 1, y + squareSize() - 1);
    painter.drawLine(x + squareSize() - 1, y + squareSize() - 1,
                     x + squareSize() - 1, y + 1);
}

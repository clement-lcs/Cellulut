#include "SimulationView.h"

SimulationView::SimulationView(QWidget *parent) : QWidget(parent), board(new SimulationBoard)
{
    displayMessage = createLabel(tr("Configurer la simulation en cliquant sur la grille"));

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);

    sliderSize = new QSlider();
    sliderSize->setMinimum(MIN_GRID_SIZE);
    sliderSize->setMaximum(MAX_GRID_SIZE);
    sliderSize->setOrientation(Qt::Orientation::Horizontal);
    sliderSize->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    inputSize = new QLineEdit();
    inputSize->setFixedWidth(30);
    inputSize->setText(QString::number(sliderSize->value()));

    QHBoxLayout *sizeLayout = new QHBoxLayout;
    sizeLayout->addWidget(new QLabel(tr("Size :")));
    sizeLayout->addWidget(inputSize);
    //sizeLayout->addWidget(sliderSize);

    QWidget *sizeSelector = new QWidget();
    sizeSelector->setLayout(sizeLayout);
    sizeSelector->setSizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
    sizeSelector->setFixedHeight(50);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("SIMULATION")), 0, 0);
    layout->addWidget(displayMessage, 1, 0);
    layout->addWidget(sizeSelector, 2, 0);
    layout->addWidget(sliderSize, 3, 0);
    layout->addWidget(startButton, 5, 0);
    layout->addWidget(board, 0, 1, 6, 2);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);

    initEvents();

    qInfo() << "SimulationView::SimulationView - constructor";
}

SimulationView::~SimulationView(){
    delete board;
    delete startButton;
    delete inputSize;
    delete sliderSize;
    delete displayMessage;

    qInfo() << "SimulationView::SimulationView - destructor";
}

void SimulationView::initEvents(){
    connect(sliderSize, &QSlider::valueChanged, this , &SimulationView::updateInputSizeValueFromInt );
    connect(inputSize, &QLineEdit::textEdited, this , &SimulationView::updateInputSizeValueFromString );

    qInfo() << "SimulationView::initEvents - events binded";
}

QLabel *SimulationView::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    return label;
}

void SimulationView::updateInputSizeValueFromInt(int newValue){
    if(newValue<MIN_GRID_SIZE || newValue>MAX_GRID_SIZE) return;
    this->board->changeGridSize(newValue);
    this->inputSize->setText(QString::number(newValue));
}

void SimulationView::updateInputSizeValueFromString(QString newValueAsStr){
    if(newValueAsStr == ""){
        return;
    }
    for(char const &c: newValueAsStr.toStdString()){
        if(isdigit(c)==0) return;
    }
    int newValue = newValueAsStr.toInt();
    if(newValue<MIN_GRID_SIZE || newValue>MAX_GRID_SIZE) return;
    this->board->changeGridSize(newValue);
    this->sliderSize->setValue(newValue);
}

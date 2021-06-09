#include "SimulationView.h"

SimulationView::SimulationView(QWidget *parent, UIEngine *_uiEngine) : QWidget(parent), uiEngine(_uiEngine)
{
    this->modelForSimulation = Automate::getAutomate()->getModel();

    this->board = new SimulationBoard(0, this->modelForSimulation->getListStates());

    this->startButton = new QPushButton(tr("&Start"));
    this->startButton->setFocusPolicy(Qt::NoFocus);

    this->sliderSize = new QSlider();
    this->sliderSize->setMinimum(MIN_GRID_SIZE);
    this->sliderSize->setMaximum(MAX_GRID_SIZE);
    this->sliderSize->setOrientation(Qt::Orientation::Horizontal);
    this->sliderSize->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    this->inputSize = new QLineEdit();
    this->inputSize->setFixedWidth(30);
    this->inputSize->setText(QString::number(sliderSize->value()));

    QHBoxLayout *sizeLayout = new QHBoxLayout;
    sizeLayout->addWidget(new QLabel(tr("Size :")));
    sizeLayout->addWidget(inputSize);

    this->sizeDisplay = new QWidget();
    sizeDisplay->setLayout(sizeLayout);
    sizeDisplay->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
    sizeDisplay->setFixedHeight(50);
    sizeDisplay->setFixedWidth(200);

    this->statesDisplay = new StatesDisplay(0, this->modelForSimulation->getListStates());

    this->gridLayout = new QGridLayout;
    setLayout(this->gridLayout);
    setStyleSheet(tr(this->styleSheet));

    setupLabelsForModel();
    setupGridLayout();
    initEvents();

    qInfo() << "SimulationView::SimulationView - constructor";
}

SimulationView::~SimulationView(){
    delete board;
    delete startButton;
    delete inputSize;
    delete sliderSize;

    qInfo() << "SimulationView::SimulationView - destructor";
}

void SimulationView::initEvents(){
    connect(sliderSize, &QSlider::valueChanged, this , &SimulationView::updateInputSizeValueFromInt );
    connect(inputSize, &QLineEdit::textEdited, this , &SimulationView::updateInputSizeValueFromString );

    qInfo() << "SimulationView::initEvents - events binded";
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

void SimulationView::setupGridLayout(){
    this->gridLayout->addWidget(createLabel("Configurer la simulation en cliquant sur la grille", "displayMessage", 14, true, true), 0, 2,1,4);
    this->gridLayout->addWidget(this->modelTitle, 1, 0,1,2);
    this->gridLayout->addWidget(this->modelDescription, 2, 0,1,2);
    this->gridLayout->addWidget(this->modelAuthor, 3, 0);
    this->gridLayout->addWidget(this->modelDate, 3, 1);
    this->gridLayout->addWidget(this->sizeDisplay, 5, 0, 1,2);
    this->gridLayout->addWidget(this->sliderSize, 6, 0, 1,2);
    this->gridLayout->addWidget(this->startButton, 7, 0,1,2);
    this->gridLayout->addWidget(this->board, 1, 2, 7, 4);
    this->gridLayout->addWidget(createLabel("Etats :", "states", 12, false, false), 1, 6,1,2);
    this->gridLayout->addWidget(this->statesDisplay, 2,6,6,2);
}

void SimulationView::setupLabelsForModel(){
    this->modelTitle = createLabel(this->modelForSimulation->getTitleAsQString(), "modelTitle", 14, true, false);
    this->modelDescription = createLabel(this->modelForSimulation->getDescriptionAsQString(), "modelDescription", 10, false, true);
    this->modelAuthor = createLabel(this->modelForSimulation->getAuthorAsQString(), "modelAuthor", 10, false, false);
    this->modelDate = createLabel(this->modelForSimulation->getDateAsQString(), "modelDate", 10, false, false);
}

QLabel *SimulationView::createLabel(const QString &text, const QString &objectName, int fontSize, bool isBold, bool isItalic){
    QLabel *label = new QLabel(text);
    label->setObjectName(objectName);
    label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);

    QFont labelFont;
    labelFont.setBold(isBold);
    labelFont.setItalic(isItalic);
    labelFont.setPointSize(fontSize);
    label->setFont(labelFont);

    return label;
}
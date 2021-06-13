#include "SurroundingFormView.h"

SurroundingFormView::SurroundingFormView(QWidget *_parent, UIEngine* _uiEngine, int surroundingIndex): QWidget(_parent), uiEngine(_uiEngine), surroundingIndex(surroundingIndex)
{
    this->gridLayout = new QGridLayout;

    Surrounding *currentSurrounding = 0;
    vector<bool>*listOfInteractions = 0;
    int boardSize = -1;
    if(surroundingIndex!=-1){
         currentSurrounding = Library::getLibrary()->get_Surrounding(surroundingIndex);
         listOfInteractions = currentSurrounding->getInteraction();
         boardSize = currentSurrounding->getRadius();
         qInfo() << "SurroundingFormView in edit mode";
    } else {
        qInfo() << "SurroundingFormView in creation mode";
    }


    if(currentSurrounding == 0)
        this->instructionMessageLabel = UIUtils::createLabel("New surrounding",12,true);
    else
        this->instructionMessageLabel = UIUtils::createLabel("View/Edit surrounding",12,true);

    this->surroundingNameLabel = UIUtils::createLabel("Label :",12,false);
    this->surroundingNameInput = new QLineEdit;

    if(currentSurrounding!=0)
        this->surroundingNameInput->setText(QString::fromStdString(currentSurrounding->getName()));

    this->surroundingRadiusLabel = UIUtils::createLabel("Radius :", 12, false);
    this->surroundingRadiusInput = new QSpinBox;
    this->surroundingRadiusInput->setValue(1);

    if(currentSurrounding!=0)
        this->surroundingRadiusInput->setValue(currentSurrounding->getRadius());

    this->surroundingRadiusInput->setMinimum(1);

    if(currentSurrounding!=0)
        this->board = new SurroundingBoard(0,listOfInteractions,boardSize);
    else
        this->board = new SurroundingBoard;

    if(this->surroundingIndex == -1)
        this->submitFormButton = UIUtils::createButton("Add");
    else
        this->submitFormButton = UIUtils::createButton("Save");

    this->cancelFormButton = UIUtils::createButton("Cancel");

    this->gridLayout->addWidget(this->instructionMessageLabel,0,0,1,2);
    this->gridLayout->addWidget(this->surroundingNameLabel, 1,0,1,1);
    this->gridLayout->addWidget(this->surroundingNameInput, 1, 1, 1, 1);
    this->gridLayout->addWidget(this->surroundingRadiusLabel, 2,0,1,1);
    this->gridLayout->addWidget(this->surroundingRadiusInput, 2,1,1,1);
    this->gridLayout->addWidget(this->board,3,0,1,2);
    this->gridLayout->addWidget(this->cancelFormButton, 4, 0, 1, 1);
    this->gridLayout->addWidget(this->submitFormButton, 4, 1, 1, 1);

    this->setLayout(this->gridLayout);

    connect(this->surroundingRadiusInput, &QSpinBox::textChanged, this->board, &SurroundingBoard::changeBoardSize);
    connect(this->submitFormButton, &QPushButton::clicked, this, &SurroundingFormView::onClickSubmit);
    connect(this->cancelFormButton, &QPushButton::clicked, this, &SurroundingFormView::onClickCancel);
}

SurroundingFormView::~SurroundingFormView()
{
    delete this->surroundingNameInput;
    delete this->surroundingNameLabel;
    delete this->instructionMessageLabel;
    delete this->surroundingRadiusLabel;
    delete this->surroundingRadiusInput;
    delete this->gridLayout;
}

void SurroundingFormView::onClickSubmit(){
    string surroundingName = this->surroundingNameInput->text().toStdString();
    int surroundingRadius = this->surroundingRadiusInput->value();

    Surrounding *surrounding;
    if(surroundingIndex!=-1){
        surrounding = Library::getLibrary()->get_Surrounding(surroundingIndex);
    } else {
        surrounding = Library::getLibrary()->create_Surrounding(surroundingName);

    }
    surrounding->setRadius(surroundingRadius);
    surrounding->setInteraction(this->board->getBoardAsVector());

    this->uiEngine->changeToLibraryView();
}

void SurroundingFormView::onClickCancel(){
    this->uiEngine->changeToLibraryView();
}

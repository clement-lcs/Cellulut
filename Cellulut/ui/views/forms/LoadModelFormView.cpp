#include "LoadModelFormView.h"

LoadModelFormView::LoadModelFormView(QWidget *parent, UIEngine *_uiEngine) : QWidget(parent), uiEngine(_uiEngine)
{
    this->instructionMessageLabel = UIUtils::createLabel(tr("Choisissez le modèle à utiliser pour la simulation"), 16, true, false);

    this->backButton = new QPushButton("Retourner au menu");
    this->backButton->setFixedHeight(150);
    this->backButton->setFont(UIUtils::getFont(12,true,false,QFont::Capitalization::AllUppercase));
    this->nextButton = new QPushButton("Lancer la simulation");
    this->nextButton->setFixedHeight(150);
    this->nextButton->setFont(UIUtils::getFont(12,true,false,QFont::Capitalization::AllUppercase));

    this->modelComboLabel = UIUtils::createLabel(tr("Modèle :"), 14, false, false);

    QStringList modelComboStringList;
    vector<Model*> *listOfModels = Library::getLibrary()->getListModels();
    for(unsigned int i = 0; i < listOfModels->size(); i++){
        modelComboStringList << listOfModels->at(i)->getTitleAsQString();
    }

    this->modelComboModel = new QStringListModel();
    this->modelComboModel->setStringList(modelComboStringList);

    this->modelCombo = new QComboBox();
    this->modelCombo->setModel(modelComboModel);

    this->gridLayout = new QGridLayout();
    this->gridLayout->addWidget(this->instructionMessageLabel,0,0,1,2);
    this->gridLayout->addWidget(this->modelComboLabel, 1,0,1,1);
    this->gridLayout->addWidget(this->modelCombo, 1,1,1,1);
    this->gridLayout->addWidget(this->backButton, 2,0,1,1);
    this->gridLayout->addWidget(this->nextButton,2,1,1,1);
    this->setLayout(this->gridLayout);

    connect(this->backButton, &QPushButton::clicked, this->uiEngine, &UIEngine::changeToMainMenuView);
    connect(this->nextButton, &QPushButton::clicked, this, &LoadModelFormView::onNextButtonClick);

    qInfo() << "LoadModelFormView::LoadModelFormView - constructor";
}

LoadModelFormView::~LoadModelFormView()
{
    delete this->gridLayout;
    delete this->instructionMessageLabel;
    delete this->modelComboModel;
    delete this->modelCombo;
    delete this->modelComboLabel;
    delete this->nextButton;
    delete this->backButton;

    qInfo() << "LoadModelFormView::LoadModelFormView - destructor";
}

void LoadModelFormView::onNextButtonClick(){
    int selectedModel = this->modelCombo->currentIndex();
    Automate::getAutomate()->setModel(Library::getLibrary()->getListModels()->at(selectedModel));
    this->uiEngine->changeToSimulationView();
}


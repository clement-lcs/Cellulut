#include "MainMenuView.h"

MainMenuView::MainMenuView(QWidget *_parent, UIEngine *_uiEngine) : QWidget(_parent), uiEngine(_uiEngine)
{
    this->welcomeMessageLabel = UIUtils::createLabel(tr("Welcome to the Cellulut application"), 25, true, false);
    this->editLibraryButton = new QPushButton("Manage the Library");
    this->editLibraryButton->setFixedHeight(150);
    this->editLibraryButton->setFont(UIUtils::getFont(15,true,false,QFont::Capitalization::AllUppercase));
    this->editLibraryButton->setStyleSheet("background-color : crimson; color: white;");

    this->createModelButton = new QPushButton("Create a Model");
    this->createModelButton->setFixedHeight(150);
    this->createModelButton->setFont(UIUtils::getFont(15,true,false,QFont::Capitalization::AllUppercase));
    this->createModelButton->setStyleSheet("background-color : crimson; color: white;");

    this->gridLayout = new QGridLayout();
    this->gridLayout->addWidget(this->welcomeMessageLabel,0,0,1,2);
    this->gridLayout->addWidget(this->editLibraryButton, 1,0,1,1);
    this->gridLayout->addWidget(this->createModelButton,1,1,1,1);
    this->setLayout(gridLayout);

    //connect(this->editLibraryButton, &QPushButton::clicked, this, &MainMenuView::editLibrary);
    connect(this->editLibraryButton, &QPushButton::clicked, this->uiEngine, &UIEngine::changeToLibraryView);
    connect(this->createModelButton, &QPushButton::clicked, this, &MainMenuView::addModel);

    qInfo() << "MainMenuView::MainMenuView - constructor";
}

MainMenuView::~MainMenuView(){
    delete this->editLibraryButton;
    delete this->createModelButton;
    delete this->welcomeMessageLabel;
    delete this->gridLayout;

    qInfo() << "MainMenuView::~MainMenuView - destructor";
}

void MainMenuView::editLibrary()
{
    QPushButton *addModelButton = new QPushButton("Add\n model");
    QPushButton *delModelButton = new QPushButton("Delete\n model");
    QPushButton *addSurroundingButton = new QPushButton("Add\n surrounding");
    QPushButton *delSurroundingButton = new QPushButton("Delete\n surrounding");

    addModelButton->setFixedHeight(80);
    delModelButton->setFixedHeight(80);
    addSurroundingButton->setFixedHeight(80);
    delSurroundingButton->setFixedHeight(80);

    addModelButton->setFont(UIUtils::getFont(9,false,false,QFont::Capitalization::AllUppercase));
    delModelButton->setFont(UIUtils::getFont(9,false,false,QFont::Capitalization::AllUppercase));
    addSurroundingButton->setFont(UIUtils::getFont(9,false,false,QFont::Capitalization::AllUppercase));
    delSurroundingButton->setFont(UIUtils::getFont(9,false,false,QFont::Capitalization::AllUppercase));

    QGridLayout* editLibraryLayout = new QGridLayout();
    editLibraryLayout->addWidget(addModelButton, 0, 0);
    editLibraryLayout->addWidget(addSurroundingButton, 0, 1);
    editLibraryLayout->addWidget(delModelButton, 1, 0);
    editLibraryLayout->addWidget(delSurroundingButton, 1, 1);

    this->editLibraryMenu = new QDialog(this);
    this->editLibraryMenu->setWindowTitle("Library");
    this->editLibraryMenu->setModal(true);
    this->editLibraryMenu->setFixedSize(250,210);
    this->editLibraryMenu->setLayout(editLibraryLayout);
    this->editLibraryMenu->show();

    connect(addModelButton, &QPushButton::clicked, this, &MainMenuView::addModel);
    connect(addModelButton,&QPushButton::clicked,this->editLibraryMenu,&QDialog::close);
    connect(delModelButton, &QPushButton::clicked, this, &MainMenuView::delModel);
    connect(addSurroundingButton, &QPushButton::clicked, this->uiEngine, &UIEngine::changeToCreateSurroundingFormView);
    connect(delSurroundingButton, &QPushButton::clicked, this, &MainMenuView::delSurrounding);
    return;
}

void MainMenuView::addModel()
{
    this-> states_added = 0;

    this->model_name = new QLineEdit;
    this->nb_states = new QSpinBox;
    this->nb_states->setMinimum(2);
    this->nb_states->setMaximum(8);

    QPushButton *cancel = new QPushButton("Return");
    QPushButton *next = new QPushButton("Next");

    QHBoxLayout *controlButtons = new QHBoxLayout;
    controlButtons->addWidget(cancel);
    controlButtons->addWidget(next);

    QFormLayout *form = new QFormLayout;
    form->addRow("Model name :", model_name);
    form->addRow("Number of states :", nb_states);

    QVBoxLayout *addModelLayout = new QVBoxLayout;
    addModelLayout->addLayout(form);
    addModelLayout->addLayout(controlButtons);

    this->addModelMenu = new QDialog(this);
    this->addModelMenu->setWindowTitle("New model");
    this->addModelMenu->setModal(true);
    this->addModelMenu->setLayout(addModelLayout);
    this->addModelMenu->show();

    QObject::connect(next,&QPushButton::clicked,this,&MainMenuView::addState);
    QObject::connect(next,&QPushButton::clicked,this->addModelMenu,&QDialog::close);
    QObject::connect(cancel,&QPushButton::clicked,this->addModelMenu,&QDialog::close);
}

void MainMenuView::addState()
{
    if (this->states_added == nb_states->value())
        return;

    QPushButton *next = new QPushButton("Next");

    QVBoxLayout *addStateLayout = new QVBoxLayout;
    //addStateLayout->addLayout(form);
    addStateLayout->addWidget(next);

    this->addStateMenu = new QDialog(this);
    this->addStateMenu->setWindowTitle("New state");
    this->addStateMenu->setModal(true);
    this->addModelMenu->setLayout(addStateLayout);
    this->addStateMenu->show();

    this->states_added += 1;

    QObject::connect(next,&QPushButton::clicked,this,&MainMenuView::addState);

    /*//Creation du Modele selon les infos récupérés dans defineState
    if(added==0)
        Library::getLibrary()->create_Model(nom->text().toStdString()); //Le modele est ajouté à la fin de la liste


    //Ajout de l'Etat récupérés dans l'appel à defineStates précedent
    if(added>0)     Library::getLibrary()->getListModels()->at(Library::getLibrary()->getListModels()->size()-1)->add_State(new State(added-1, label->text().toStdString(), nom->text().toStdString())); // State dead added


    if (added==nb->value())
        return;

    added++;

    label = new QLineEdit;
    nom = new QLineEdit("black");

    QPushButton *suivant = new QPushButton("Suivant");

    QFormLayout *form = new QFormLayout;
        form->addRow("label:", label);
        form->addRow("Couleur:", nom);

    QVBoxLayout *vertical = new QVBoxLayout;
        vertical->addLayout(form);
        vertical->addWidget(suivant);

    label->setText(QString::number(added-1));

    infos = new QDialog(this);
        QString concat = "Definir Etat n°" + QString::number(added);
        infos->setWindowTitle(concat);
        infos->setModal(true);
        infos->setLayout(vertical);
        infos->show();

    QObject::connect(suivant,&QPushButton::clicked,this,&MainMenuView::addState);
    QObject::connect(suivant,&QPushButton::clicked,infos,&QDialog::close);*/

}


void MainMenuView::delModel()
{
    this->delModelMenu = new QDialog(this);
    this->delModelMenu->setWindowTitle("Suppression d'un modèle");
    this->delModelMenu->setModal(true);
    //delModelMenu->setLayout(delModelLayout);
    this->delModelMenu->show();
}

void MainMenuView::delSurrounding()
{
    this->delSurroundingMenu = new QDialog(this);
    this->delSurroundingMenu->setWindowTitle("Suppression d'un voisinage");
    this->delSurroundingMenu->setModal(true);
    //delSurroundingMenu->setLayout(delSurroundingLayout);
    this->delSurroundingMenu->show();
}


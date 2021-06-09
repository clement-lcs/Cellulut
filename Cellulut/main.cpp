#include "main.h"

#include <QApplication>
#include "data/DataEngine.h"
#include "ui/UIEngine.h"
#include "models/Library.h"
#include "models/Automate.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    /*QApplication app(argc, argv);

    DataEngine *dataEngine = new DataEngine();
    UIEngine *uiEngine = new UIEngine(&app);

    uiEngine->setInsideDataForUI(dataEngine->getInsideDataForUI());
    dataEngine->setInsideUIForData(uiEngine->getInsideUIForData());

    uiEngine->start();
    uiEngine->changeToSimulationView();

    return app.exec();*/

    Automate::getAutomate()->setModel(Library::getLibrary()->getListModels()->at(0));
    Automate::getAutomate()->init_Grid(5,5);
    Automate::getAutomate()->random_init();
    cout<<endl;
    Automate::getAutomate()->afficher_grid();
    cout<<endl;
    Automate::getAutomate()->afficher_grid();
    Automate::getAutomate()->next_generation();
    cout<<endl;

    cout<<endl;

    Automate::getAutomate()->setModel(Library::getLibrary()->getListModels()->at(1));
    Automate::getAutomate()->init_Grid(5,5);
    Automate::getAutomate()->random_init();
    cout<<endl;
    Automate::getAutomate()->afficher_grid();
    cout<<endl;
    Automate::getAutomate()->afficher_grid();
    Automate::getAutomate()->next_generation();
    cout<<endl;
    Library::getLibrary()->del_Model(0);
    Library::getLibrary()->del_Model(1);
    Library::getLibrary()->del_Model(2);

    return 0;
}

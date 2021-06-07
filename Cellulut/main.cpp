#include "main.h"

#include <QApplication>
#include "data/DataEngine.h"
#include "ui/UIEngine.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DataEngine *dataEngine = new DataEngine();
    UIEngine *uiEngine = new UIEngine(&app);

    uiEngine->setInsideDataForUI(dataEngine->getInsideDataForUI());
    dataEngine->setInsideUIForData(uiEngine->getInsideUIForData());

    uiEngine->start();

    return app.exec();
}

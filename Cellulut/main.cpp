#include "main.h"
#include <QApplication>
#include "controllers/c_mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Instantiate main window controller and display view
    C_MainWindow *mainWindowController = new C_MainWindow(&app);

    // Initialize event binding, etc..

    // Show the view
    mainWindowController->getView()->show();

    return app.exec();
}

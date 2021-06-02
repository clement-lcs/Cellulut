#include "main.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("yo le boss");
    bouton.show();

    return app.exec();
}

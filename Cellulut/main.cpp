#include "main.h"
#include <QApplication>
#include "controllers/c_mainwindow.h"
#include "views/v_mainwindow.h"
#include "views/v_startmenu.h"

int main(int argc, char *argv[])
{
    /*
    c_mainwindow* controller = new c_mainwindow(&app);
    controller->getView()->show();

    string str = "hello world";
    QString qstr = QString::fromStdString(str);

    QWidget fenetre;
    fenetre.setFixedSize(300, 150);

    QPushButton bouton("default", &fenetre);
    bouton.setCursor(Qt::PointingHandCursor);
    bouton.setText(qstr);

    fenetre.show();

    Cellulut* test = new Cellulut();
    test->show();


    */
    QApplication app(argc, argv);
    v_startmenu test;
    test.show();
    return app.exec();
}

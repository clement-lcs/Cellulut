#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H

#include "views/v_mainwindow.h"

class V_MainWindow;

/*!
 *  Classe faisant le lien entre modèles et vues
 */

class C_MainWindow
{
private:
    QApplication* qapp;
    V_MainWindow* view; /*!< View */

    public:
    C_MainWindow(QApplication* app);
    ~C_MainWindow();

    V_MainWindow* getView() const { return view; }

    void init();

    void bindActions();
    void onLoadTemplate();
    void onCreateTemplate();
};

#endif // C_MAINWINDOW_H

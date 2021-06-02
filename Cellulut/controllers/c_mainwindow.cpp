#include "main.h"
#include "c_mainwindow.h"
#include "../views/v_mainwindow.h"
#include "../views/v_createtemplateform.h"
#include "../views/v_loadtemplateform.h"
#include "ui_v_mainwindow.h"
#include "ui_v_loadtemplateform.h"


C_MainWindow::C_MainWindow(QApplication *q) {
    // Keep a reference to QApplication inside the main window controller
    this->qapp = q;

    // Instantiate the view the controller is responsible for
    this->view = new V_MainWindow(0, this);
}

C_MainWindow::~C_MainWindow()
{
    delete view;
}

void C_MainWindow::onLoadTemplate() {
    // This method will trigger everything related to loading a template : create the view, initialize the view, show the view.
    // Just as in the main.cpp file
    V_LoadTemplateForm* loadTemplateForm = new V_LoadTemplateForm(0, this);
    loadTemplateForm->show();
}

void C_MainWindow::onCreateTemplate() {
    // This method will trigger everything related to creating a template : create the view, initialize the view, show the view.
    // Just as in the main.cpp file
    V_CreateTemplateForm* createTemplateForm = new V_CreateTemplateForm(0, this);
    createTemplateForm->show();
}

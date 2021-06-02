#include "main.h"
#include "c_mainwindow.h"
#include "../views/v_mainwindow.h"
#include "ui_v_mainwindow.h"

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

void C_MainWindow::init(){
    this->bindActions();
}

void C_MainWindow::bindActions(){
    // The controller bind events in the view to onXXX methods (event binders) in the view
    this->view->connect(this->getView()->getUi()->actionLoadTemplate, SIGNAL(triggered()), qapp, SLOT(onLoadTemplate()));
    this->view->connect(this->getView()->getUi()->actionCreateTemplate, SIGNAL(triggered()), qapp, SLOT(onCreateTemplate()));
}

void C_MainWindow::onLoadTemplate() {
    // This method will trigger everything related to loading a template : create the view, initialize the view, show the view.
    // Just as in the main.cpp file
}

void C_MainWindow::onCreateTemplate() {
    // This method will trigger everything related to creating a template : create the view, initialize the view, show the view.
    // Just as in the main.cpp file
}

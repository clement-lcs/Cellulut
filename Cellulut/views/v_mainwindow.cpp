#include "main.h"
#include "v_mainwindow.h"
#include "ui_v_mainwindow.h"

V_MainWindow::V_MainWindow(QWidget *parent, C_MainWindow *c) : QMainWindow(parent), ui(new Ui::V_MainWindow)
{
    this->ui->setupUi(this);
    this->controller = c;
}

V_MainWindow::~V_MainWindow()
{
    delete this->ui;
}

void V_MainWindow::onLoadTemplate()
{
    // This method is called when the button "loadTemplate" is clicked
    // This method is just a bridge to the correct controller method
    this->controller->onLoadTemplate();
}

void V_MainWindow::onCreateTemplate()
{
    // This method is called when the button "createTemplate" is clicked
    // This method is just a bridge to the correct controller method
    this->controller->onCreateTemplate();
}


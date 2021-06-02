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

void V_MainWindow::on_actionLoadTemplate_clicked()
{
    this->controller->onLoadTemplate();
}


void V_MainWindow::on_actionCreateTemplate_clicked()
{
    this->controller->onCreateTemplate();
}


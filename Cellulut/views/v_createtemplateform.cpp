#include "v_createtemplateform.h"
#include "ui_v_createtemplateform.h"

V_CreateTemplateForm::V_CreateTemplateForm(QWidget *w, C_MainWindow *c) : QDialog(w), ui(new Ui::V_CreateTemplateForm)
{
    ui->setupUi(this);
    this->controller = c;
}

V_CreateTemplateForm::~V_CreateTemplateForm()
{
    delete this->ui;
}

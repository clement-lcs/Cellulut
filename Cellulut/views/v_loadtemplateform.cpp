#include "v_loadtemplateform.h"
#include "ui_v_loadtemplateform.h"

V_LoadTemplateForm::V_LoadTemplateForm(QWidget *w, C_MainWindow *c) : QDialog(w), ui(new Ui::V_LoadTemplateForm)
{
    ui->setupUi(this);
    this->controller = c;
}

V_LoadTemplateForm::~V_LoadTemplateForm()
{
    delete this->ui;
}

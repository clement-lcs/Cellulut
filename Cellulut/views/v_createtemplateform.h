#ifndef V_CREATETEMPLATEFORM_H
#define V_CREATETEMPLATEFORM_H

#include <QDialog>
#include "../controllers/c_mainwindow.h"

namespace Ui {
class V_CreateTemplateForm;
}

class V_CreateTemplateForm : public QDialog
{
    Q_OBJECT
private:
    Ui::V_CreateTemplateForm *ui;
    C_MainWindow *controller;
public:
    explicit V_CreateTemplateForm(QWidget *parent = 0, C_MainWindow *c = 0);
    ~V_CreateTemplateForm();

    Ui::V_CreateTemplateForm* getUi() const {return this->ui;}

};

#endif // V_CREATETEMPLATEFORM_H

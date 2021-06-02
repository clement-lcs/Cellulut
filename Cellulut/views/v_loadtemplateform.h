#ifndef V_LOADTEMPLATEFORM_H
#define V_LOADTEMPLATEFORM_H


#include <QDialog>
#include "../controllers/c_mainwindow.h"

namespace Ui {
class V_LoadTemplateForm;
}

class V_LoadTemplateForm : public QDialog
{
    Q_OBJECT
private:
    Ui::V_LoadTemplateForm *ui;
    C_MainWindow *controller;
public:
    explicit V_LoadTemplateForm(QWidget *parent = 0, C_MainWindow *c = 0);
    ~V_LoadTemplateForm();

    Ui::V_LoadTemplateForm* getUi() const {return this->ui;}

};

#endif // V_LOADTEMPLATEFORM_H



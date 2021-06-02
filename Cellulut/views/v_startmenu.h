#ifndef V_STARTMENU_H
#define V_STARTMENU_H

#include <QDialog>

namespace Ui {
class v_startmenu;
}

class v_startmenu : public QDialog
{
    Q_OBJECT

public:
    explicit v_startmenu(QWidget *parent = nullptr);
    ~v_startmenu();

private:
    Ui::v_startmenu *ui;
};

#endif // V_STARTMENU_H

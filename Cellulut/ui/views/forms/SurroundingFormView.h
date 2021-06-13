#ifndef SURROUNDINGFORMVIEW_H
#define SURROUNDINGFORMVIEW_H

#include "main.h"
#include "ui/UIEngine.h"
#include "SurroundingBoard.h"

class SurroundingFormView : public QWidget
{
    Q_OBJECT
public:
    SurroundingFormView(QWidget *parent = 0, UIEngine *uiEngine = 0, int surroundingIndex = -1);
    ~SurroundingFormView();

    void onClickSubmit();
    void onClickCancel();
private:
    UIEngine *uiEngine;
    int surroundingIndex;
    QGridLayout *gridLayout;
    QLabel *instructionMessageLabel;
    QLabel *surroundingNameLabel;
    QLineEdit *surroundingNameInput;
    QLabel *surroundingRadiusLabel;
    QSpinBox *surroundingRadiusInput;
    SurroundingBoard *board;
    QPushButton *submitFormButton;
    QPushButton *cancelFormButton;
};

#endif // SURROUNDINGFORMVIEW_H

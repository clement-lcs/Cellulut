#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include "main.h"
#include "ui/UIEngine.h"

class UIEngine;

class MainMenuView : public QWidget
{
    Q_OBJECT
    public:
        MainMenuView(QWidget *parent = 0, UIEngine *uiEngine = 0);
        ~MainMenuView();

    signals:
        void createModelClicked();

    private:
        UIEngine *uiEngine;
        QLabel *welcomeMessageLabel;
        QPushButton *createModelButton;
        QPushButton *editLibraryButton;
        QGridLayout *gridLayout;
        QDialog* editLibraryMenu;
        QDialog* addModelMenu;
        QDialog* addStateMenu;
        QDialog* delModelMenu;
        QDialog* addSurroundingMenu;
        QDialog* delSurroundingMenu;
        QDialog* addRuleMenu;

        QLineEdit* model_name;
        QSpinBox* nb_states;
        unsigned int states_added;

        QLineEdit* state_label;
        QComboBox* colorsCombo;

        QComboBox *modelCombo;
        QStringListModel *modelComboModel;

    private slots:
        void editLibrary();
        void addModel();
        void addState();
        void delModel();
        void delSurrounding();
        void addRule();
        void onClickSubmitDelModel();
};

#endif // MAINMENUVIEW_H

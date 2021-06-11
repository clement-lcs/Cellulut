QT += widgets
QT += core gui sql

SOURCES += \
    main.cpp \
    models/Automate.cpp \
    models/Cell.cpp \
    models/Cellulut.cpp \
    models/Grid.cpp \
    models/Library.cpp \
    models/Model.cpp \
    models/Rule.cpp \
    models/State.cpp \
    models/Surrounding.cpp \
    models/managers/DatabaseManager.cpp \
    models/managers/ModelsManager.cpp \
    models/managers/StatesManager.cpp \
    ui/UIEngine.cpp \
    ui/UIUtils.cpp \
    ui/views/MainWindow.cpp \
    ui/views/forms/LoadModelFormView.cpp \
    ui/views/menu/MainMenuView.cpp \
    ui/views/simulation/SimulationButtonsBar.cpp \
    ui/views/simulation/SimulationThread.cpp \
    ui/views/simulation/SimulationView.cpp \
    ui/views/simulation/SimulationBoard.cpp \
    ui/views/simulation/StatesDisplay.cpp

HEADERS += \
    main.h \
    models/Automate.h \
    models/Cell.h \
    models/Cellulut.h \
    models/Grid.h \
    models/Library.h \
    models/Model.h \
    models/Rule.h \
    models/State.h \
    models/Surrounding.h \
    models/managers/DatabaseManager.h \
    models/managers/ModelsManager.h \
    models/managers/StatesManager.h \
    ui/UIEngine.h \
    ui/UIUtils.h \
    ui/views/MainWindow.h \
    ui/views/forms/LoadModelFormView.h \
    ui/views/menu/MainMenuView.h \
    ui/views/simulation/SimulationButtonsBar.h \
    ui/views/simulation/SimulationThread.h \
    ui/views/simulation/SimulationView.h \
    ui/views/simulation/SimulationBoard.h \
    ui/views/simulation/StatesDisplay.h

FORMS +=

RESOURCES += \
    Cellulut.qrc

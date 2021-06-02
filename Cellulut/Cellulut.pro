QT += widgets
QT += core gui

SOURCES += \
    controllers/c_mainwindow.cpp \
    main.cpp \
    models/Automate.cpp \
    models/Cell.cpp \
    models/Grid.cpp \
    models/Library.cpp \
    models/Model.cpp \
    models/Rule.cpp \
    models/State.cpp \
    models/Surrounding.cpp \
    views/v_mainwindow.cpp \
    views/v_startmenu.cpp

HEADERS += \
    controllers/c_mainwindow.h \
    main.h \
    models/Automate.h \
    models/Cell.h \
    models/Grid.h \
    models/Library.h \
    models/Model.h \
    models/Rule.h \
    models/State.h \
    models/Surrounding.h \
    views/v_mainwindow.h \
    views/v_startmenu.h

FORMS += \
    views/v_mainwindow.ui \
    views/v_startmenu.ui


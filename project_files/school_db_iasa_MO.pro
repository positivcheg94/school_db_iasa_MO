#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T18:59:44
#
#-------------------------------------------------

QT += core gui
QT += sql
QT += core
QT += opengl
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = school_db_iasa_MO
TEMPLATE = app

SOURCES = window_manager.cpp\
    login_screen.cpp \
    manager_menu.cpp \
    mainwindow.cpp \
    main.cpp\




HEADERS = window_manager.h\
    mainwindow.h \
    login_screen.h \
    manager_menu.h \


FORMS = mainwindow.ui\
    login_screen.ui \
    manager_menu.ui

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

SOURCES =\
    login_screen.cpp \
    manager_menu.cpp \
    mainwindow.cpp \
    main.cpp\
    windows_manager.cpp \
    manager_windows/new_human_picker.cpp \
    student_menu.cpp \
    menu_base.cpp




HEADERS =\
    mainwindow.h \
    login_screen.h \
    manager_menu.h \
    windows_manager.h \
    manager_windows/new_human_picker.h \
    student_menu.h \
    menu_base.h


FORMS = mainwindow.ui\
    login_screen.ui \
    manager_menu.ui \
    manager_windows/new_human_picker.ui \
    student_menu.ui

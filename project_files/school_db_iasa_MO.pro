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
    manager_windows/add_new_job.cpp \
    manager_windows/add_new_subject.cpp\
    student_menu.cpp




HEADERS =\
    mainwindow.h \
    login_screen.h \
    manager_menu.h \
    windows_manager.h \
    manager_windows/new_human_picker.h \
    manager_windows/add_new_job.h \
    manager_windows/add_new_subject.h\
    student_menu.h


FORMS = mainwindow.ui\
    login_screen.ui \
    manager_menu.ui \
    manager_windows/new_human_picker.ui \
    manager_windows/add_new_job.ui \
    manager_windows/add_new_subject.ui\
    student_menu.ui

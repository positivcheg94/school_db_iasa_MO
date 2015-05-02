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


SOURCES += main.cpp\
    mainwindow.cpp \
    login_screen.cpp

HEADERS  += mainwindow.h \
    login_screen.h

FORMS    += mainwindow.ui\
    login_screen.ui

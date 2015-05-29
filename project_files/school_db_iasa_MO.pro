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
    student_menu.cpp \
    menu_base.cpp \
    teacher_menu.cpp \
    teacher_windows/add_marks.cpp \
    manager_windows/change_job.cpp \
    manager_windows/administrate_position.cpp \
    manager_windows/expire_position.cpp \
    manager_windows/assign_human_to_position.cpp \
    learning_manager_menu.cpp \
    manager_windows/expire_human_on_position.cpp




HEADERS =\
    mainwindow.h \
    login_screen.h \
    manager_menu.h \
    windows_manager.h \
    manager_windows/new_human_picker.h \
    manager_windows/add_new_job.h \
    manager_windows/add_new_subject.h\
    student_menu.h \
    menu_base.h \
    teacher_menu.h \
    teacher_windows/add_marks.h \
    manager_windows/change_job.h \
    manager_windows/administrate_position.h \
    manager_windows/expire_position.h \
    manager_windows/assign_human_to_position.h \
    learning_manager_menu.h \
    manager_windows/expire_human_on_position.h


FORMS = mainwindow.ui\
    login_screen.ui \
    manager_menu.ui \
    manager_windows/new_human_picker.ui \
    manager_windows/add_new_job.ui \
    manager_windows/add_new_subject.ui\
    student_menu.ui \
    teacher_menu.ui \
    teacher_windows/add_marks.ui \
    manager_windows/change_job.ui \
    manager_windows/administrate_position.ui \
    manager_windows/expire_position.ui \
    manager_windows/assign_human_to_position.ui \
    learningmanagermenu.ui \
    manager_windows/expire_human_on_position.ui

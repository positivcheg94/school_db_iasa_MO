#ifndef WINDOWS_MANAGER_H
#define WINDOWS_MANAGER_H

//read config
#include <fstream>

#include "login_screen.h"

#include "manager_menu.h"
#include "student_menu.h"
#include "teacher_menu.h"

#include "mainwindow.h"

#include <QObject>
#include <QSqlDatabase>


//debug stuff
#include <QMessageBox>
#include <QDebug>

extern QString HOST;
extern int PORT;
extern QString DBNAME;

class windows_manager : public QObject
{
    Q_OBJECT
public:
    explicit windows_manager(QObject *parent = 0);
    ~windows_manager();

    void show_login();

signals:

private slots:
    void process_login(QString role, QString username);
    void show_main_window(QSqlQueryModel* model);
    void hide_main_window();
private:
    //database
    QSqlDatabase db;
    QString db_login;
    //login screen
    login_screen* ls;

    //menu hanle
    menu_base* menu;

    //sql_query_viewers
    MainWindow* mainwin;
};

#endif // WINDOWS_MANAGER_H

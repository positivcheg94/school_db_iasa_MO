#ifndef WINDOWS_MANAGER_H
#define WINDOWS_MANAGER_H

#include "login_screen.h"

#include "manager_menu.h"


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
    void show_main_window(QSqlQueryModel* model);
signals:

private slots:
    void process_login(QString role);

private:
    QSqlDatabase db;
    login_screen* ls;
    manager_menu* man_menu;
    MainWindow* mainwin;
};

#endif // WINDOWS_MANAGER_H

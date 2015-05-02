#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "login_screen.h"

#include <QObject>

#include <QSqlDatabase>

extern QString HOST;
extern int PORT;
extern QString DBNAME;

class window_manager : public QObject
{
    Q_OBJECT
public:
    explicit window_manager(QObject *parent = 0);
    ~window_manager();

    void show_login();

signals:

public slots:

private:
    QSqlDatabase db;
    login_screen* ls;
};

#endif // WINDOW_MANAGER_H

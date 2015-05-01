#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QString host = QString("176.36.190.134");
    QString dbname = QString("school");
    QString user = QString("postgres");
    QString pswd = QString("yang_db");

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(host);
    db.setPort(5432);
    db.setDatabaseName(dbname);
    db.setUserName(user);
    db.setPassword(pswd);
    db.setConnectOptions("connect_timeout=2");
    bool connectioncheck = db.open();

    if (connectioncheck == true){
        qDebug() << "Connection to database established." << endl;
    }
    else {
        qDebug() << "Error for database " << db.databaseName() << " :" << db.lastError().text() << endl;
    }
    qDebug() << "Closing" << endl;
    db.close();
    qDebug() << "Closed" << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

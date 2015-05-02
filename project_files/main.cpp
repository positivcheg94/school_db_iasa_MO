#include "mainwindow.h"
#include "login_screen.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

const QString HOST = "localhost";
const int PORT = 5432;
const QString DBNAME = "school";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(HOST);
    db.setPort(5432);
    db.setDatabaseName(DBNAME);
    db.setConnectOptions("connect_timeout=2");

    /*
    QString host = QString("localhost");
    QString dbname = QString("school");
    QString user = QString("admin_ivanov");
    QString pswd = QString("55555");

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(host);
    db.setPort(5432);
    db.setDatabaseName(dbname);
    db.setUserName(user);
    db.setPassword(pswd);
    db.setConnectOptions("connect_timeout=2");
    QSqlDatabase ddb = QSqlDatabase(db);
    bool connectioncheck = ddb.open();

    if (connectioncheck == true){
        qDebug() << "Connection to database established." << endl;
    }
    else {
        qDebug() << "Error for database " << db.databaseName() << " :" << db.lastError().text() << endl;
    }
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel;
    query.exec("SELECT * FROM positions");
    model->setQuery(query);


    MainWindow w;
    w.show();

    QTableView* table = w.getTable();
    table->setModel(model);

    QMessageBox box;
    box.setText("GTFO");
    box.exec();

    qDebug() << "Closing" << endl;
    ddb.close();
    qDebug() << "Closed" << endl;
    delete model;
    */

    login_screen ls(db);
    ls.show();

    return a.exec();
}

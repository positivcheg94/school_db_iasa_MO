#include "mainwindow.h"
#include "login_screen.h"

#include <QObject>
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

class window_manager : public QObject{

    Q_OBJECT

public:
    window_manager(QSqlDatabase &database){
        ls = new login_screen(database);

    }

    ~window_manager(){
        delete ls;
    }


private:
    login_screen* ls;




signals:


private slots:

};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(HOST);
    db.setPort(5432);
    db.setDatabaseName(DBNAME);
    db.setConnectOptions("connect_timeout=2");

    login_screen ls(db);
    ls.show();

    return a.exec();
}

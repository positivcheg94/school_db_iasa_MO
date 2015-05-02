#include "window_manager.h"

QString HOST = "localhost";
int PORT = 5432;
QString DBNAME = "school";

window_manager::window_manager(QObject *parent) : QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(HOST);
    db.setPort(5432);
    db.setDatabaseName(DBNAME);
    db.setConnectOptions("connect_timeout=2");
    ls = new login_screen(db);
}

window_manager::~window_manager(){
    delete ls;
}

void window_manager::show_login(){
    ls->show();
}



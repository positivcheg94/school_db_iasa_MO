#include "windows_manager.h"

QString HOST = "localhost";
int PORT = 5432;
QString DBNAME = "school";

windows_manager::windows_manager(QObject *parent) : QObject(parent)
{
    db=QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(HOST);
    db.setPort(5432);
    db.setDatabaseName(DBNAME);
    db.setConnectOptions("connect_timeout=2");
    ls = new login_screen(db);
    connect(ls,SIGNAL(loginSucceed(QString)),this,SLOT(process_login(QString)));
}

windows_manager::~windows_manager(){
    delete ls;
}

void windows_manager::show_login(){
    ls->show();
}

void windows_manager::process_login(QString role){
    ls->hide();

    if (role == "student"){
        qDebug() << "role - student";

    }
    else if (role == "hr"){
        qDebug() << "role - hr";

    }
    else if (role == "hr"){
        qDebug() << "role - teacher";

    }
    else if (role == "hr"){
        qDebug() << "role - admin";

    }
    else{
        qDebug() << "role - postgre? or error";

    }

    QMessageBox msg;
    msg.setText("login ok");
    msg.exec();
}



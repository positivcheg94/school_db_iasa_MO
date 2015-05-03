#include "windows_manager.h"

QString HOST = "176.36.190.134";
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

    //todo: depending on role, process_login should create menu from menus abstract factory
    man_menu = new manager_menu;

    connect(man_menu,SIGNAL(open_main_window(QString)),this,SLOT(show_main_window(QString)));

    mainwin = new MainWindow;
}

windows_manager::~windows_manager(){
    if(ls) delete ls;
    if(man_menu) delete man_menu;
    if(mainwin) delete mainwin;
}

void windows_manager::show_login(){
    ls->show();
}

void windows_manager::show_main_window(QString table){
    mainwin->loadModel(table);
    man_menu->hide();
    mainwin->show();
}

void windows_manager::hide_main_window(){
    mainwin->hide();
    man_menu->show();
}

void windows_manager::process_login(QString role){
    ls->hide();
    qDebug() << role << endl;
    if (role == "student"){
        qDebug() << "role - student";

    }
    else if (role == "hr"){
        qDebug() << "role - hr";
        man_menu->show();

    }
    else if (role == "teacher"){
        qDebug() << "role - teacher";

    }
    else if (role == "admin"){
        qDebug() << "role - admin";

    }
    else{
        qDebug() << "role - postgre or error";

    }

    QMessageBox msg;
    msg.setText("login ok");
    msg.exec();
}



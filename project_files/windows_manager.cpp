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

    mainwin = new MainWindow;

    connect(mainwin,SIGNAL(close_main_window()),this,SLOT(hide_main_window()));

}

windows_manager::~windows_manager(){
    if(ls) delete ls;
    if(menu) delete menu;
    if(mainwin) delete mainwin;
}

void windows_manager::show_login(){
    ls->show();
}

void windows_manager::show_main_window(QSqlQueryModel* model){
    mainwin->loadModel(model);
    menu->hide();
    mainwin->show();
}

void windows_manager::hide_main_window(){
    mainwin->hide();
    menu->show();
}

void windows_manager::process_login(QString role){
    ls->hide();
    qDebug() << "role - " << role << endl;
    if (role == "student"){
        menu = new student_menu;

    }
    else if (role == "manager"){
        //todo: depending on role, process_login should create menu from menus abstract factory
        menu = new manager_menu;


    }
    else if (role == "teacher"){

    }
    else if (role == "admin"){

    }
    else{

    }
    if(menu) connect(menu,SIGNAL(open_main_window(QSqlQueryModel*)),this,SLOT(show_main_window(QSqlQueryModel*)));
    menu->show();
    QMessageBox msg;
    msg.setText("login ok");
    msg.exec();
}



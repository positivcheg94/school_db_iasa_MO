#include "windows_manager.h"

QString HOST = "176.36.190.134";
int PORT = 5432;
QString DBNAME = "school";

windows_manager::windows_manager(QObject *parent) : QObject(parent)
{
    std::fstream config("config.cfg",std::ios_base::in);
    if(config.is_open()){
        std::string host;
        int port;
        std::string dbname;
        config >> host >> port >> dbname;
        config.close();
        HOST = QString(host.c_str());
        PORT = port;
        DBNAME = QString(dbname.c_str());
    }
    db=QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(HOST);
    db.setPort(PORT);
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
    msg.setText(QString("Connected to %1:%2 as %3 successfully").arg(HOST, QString::number(PORT), role));
    msg.exec();
}



#include "windows_manager.h"

#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "singleton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    windows_manager* wm = &Singleton<windows_manager>::Instance();
    wm->show_login();

    return a.exec();
}

#ifndef STUDENT_MENU_H
#define STUDENT_MENU_H



#include "menu_base.h" //which is actually QMainWindow

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class student_menu;
}

class student_menu : public menu_base
{
    Q_OBJECT

public:
    explicit student_menu(QWidget *parent = 0);
    virtual ~student_menu();

private slots:
    void on_see_rozklad_clicked();
    virtual void restore_menu();
private:
    Ui::student_menu *ui;
};

#endif // STUDENT_MENU_H

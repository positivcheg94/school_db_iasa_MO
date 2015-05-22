#ifndef TEACHER_MENU_H
#define TEACHER_MENU_H


#include "menu_base.h" //which is actually QMainWindow
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include "teacher_windows/add_marks.h"

namespace Ui {
class teacher_menu;
}

class teacher_menu : public menu_base
{
    Q_OBJECT

public:
    explicit teacher_menu(QWidget *parent = 0, QString db_login="");
    ~teacher_menu();

private slots:
    virtual void restore_menu();

    void on_marks_clicked();

private:
    Ui::teacher_menu *ui;
    add_marks* a_marks;
    int staff_id;
};

#endif // TEACHER_MENU_H

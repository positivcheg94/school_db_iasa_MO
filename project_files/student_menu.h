#ifndef STUDENT_MENU_H
#define STUDENT_MENU_H



#include "menu_base.h" //which is actually QMainWindow

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class student_menu;
}

class student_menu : public menu_base
{
    Q_OBJECT

public:
    explicit student_menu(QWidget *parent = 0, QString db_login="");
    virtual ~student_menu();

private slots:
    void on_see_rozklad_clicked();
    virtual void restore_menu();
    void on_show_marks_clicked();

private:
    Ui::student_menu *ui;
    int student_id;
    QString class_name;
};

#endif // STUDENT_MENU_H

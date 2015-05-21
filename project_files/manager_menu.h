#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include "manager_windows/new_human_picker.h"
#include "manager_windows/add_new_subject.h"
#include "manager_windows/add_new_job.h"

#include "menu_base.h" //which is actually QMainWindow
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class manager_menu;
}

class manager_menu : public menu_base
{
    Q_OBJECT

public:
    explicit manager_menu(QWidget *parent = 0);
    virtual ~manager_menu();

signals:
    void show_add_job_dialog(QSqlQueryModel*);


private slots:
    virtual void restore_menu();

    //buttons
    void on_show_humans_button_clicked();

    void on_add_new_human_button_clicked();
    void on_add_new_subject_button_clicked();
    void on_add_new_job_button_clicked();

private:
    Ui::manager_menu *ui;
    new_human_picker* n_human_picker;
    add_new_subject* a_new_subject;
    add_new_job* a_new_job;

};

#endif // MANAGER_MENU_H

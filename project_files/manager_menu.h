#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include "manager_windows/new_human_picker.h"
#include "manager_windows/add_new_subject.h"
#include "manager_windows/add_new_job.h"
#include "manager_windows/change_job.h"
#include "manager_windows/administrate_position.h"
#include "manager_windows/expire_position.h"
#include "manager_windows/assign_human_to_position.h"

#include "learning_manager_menu.h"
#include "menu_base.h" //which is actually QMainWindow
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

namespace Ui {
class manager_menu;
}

class manager_menu : public menu_base
{
    Q_OBJECT

public:
    explicit manager_menu(QWidget *parent = 0, QString db_login="");
    virtual ~manager_menu();

signals:
    void show_add_new_job_dialog(QSqlQueryModel*);
    void show_change_job_dialog(QSqlQueryModel*,QSqlQueryModel*);
    void show_administrating_positions_dialog(QSqlQueryModel*);
    void show_expire_position_dialog(QSqlQueryModel*);
    void show_assign_human_to_position_dialog(QSqlQueryModel*,QSqlQueryModel*);


private slots:
    virtual void restore_menu();

    //buttons
        //show
        void on_show_humans_button_clicked();
        void on_show_subjects_button_clicked();
        void on_show_positions_button_clicked();
        void on_show_administrating_positions_button_clicked();
        void on_show_personel_button_clicked();

    void on_add_new_human_button_clicked();
    void on_add_new_subject_button_clicked();
    void on_add_new_job_button_clicked();
    void on_change_job_button_clicked();
    void on_administrate_position_button_clicked();
    void on_end_position_button_clicked();
    void on_assign_human_job_button_clicked();
    void on_show_learning_manager_menu_button_clicked();
    
private:
    Ui::manager_menu *ui;
    new_human_picker* n_human_picker;
    add_new_subject* a_new_subject;
    add_new_job* a_new_job;
    change_job* ch_job;
    administrate_position* ad_positions;
    expire_position* exp_position;
    assign_human_to_position* ass_human_to_position;
    learning_manager_menu* learn_man_menu;
    int staff_id;

};

#endif // MANAGER_MENU_H

#ifndef LEARNINGMANAGERMENU_H
#define LEARNINGMANAGERMENU_H


#include "menu_base.h" //which is actually QMainWindow
#include "learning_manager_windows/add_new_student.h"
#include "learning_manager_windows/add_new_class.h"
#include "learning_manager_windows/assign_pupil_to_class.h"
#include "learning_manager_windows/add_schedule_entry.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QCloseEvent>


namespace Ui {
class LearningManagerMenu;
}

class learning_manager_menu : public menu_base
{
    Q_OBJECT

public:
    explicit learning_manager_menu(QWidget *parent = 0);
    ~learning_manager_menu();
    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    virtual void restore_menu();

    void on_addPupil_clicked();

    void on_addPupilToClass_clicked();

    void on_addClass_clicked();

    void on_view_classes_clicked();

    void on_addSchedule_clicked();

private:
    Ui::LearningManagerMenu *ui;
    add_new_student* a_n_s;
    add_new_class* a_n_c;
    assign_pupil_to_class* a_p_t_c;
    add_schedule_entry* a_s_e;
    int staff_id;
};

#endif // LEARNINGMANAGERMENU_H

#ifndef ADD_NEW_JOB_H
#define ADD_NEW_JOB_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>


//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class add_new_job;
}

class add_new_job : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_job(QWidget *parent = 0);
    ~add_new_job();

    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void show_add_new_job_dialog(QSqlQueryModel* model);

    void on_submit_new_position_button_clicked();

    void on_is_teacher_checkbox_stateChanged(int state);

private:
    Ui::add_new_job *ui;
};

#endif // ADD_NEW_JOB_H

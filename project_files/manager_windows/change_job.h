#ifndef CHANGE_JOB_H
#define CHANGE_JOB_H

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
class change_job;
}

class change_job : public QWidget
{
    Q_OBJECT

public:
    explicit change_job(QWidget *parent = 0);
    ~change_job();

    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void show_change_job_dialog(QSqlQueryModel* model, QSqlQueryModel *model_subj);

    void on_is_teacher_checkbox_stateChanged(int state);

    void on_submit_position_button_clicked();

    void on_pick_position_combobox_currentIndexChanged(int index);

private:
    Ui::change_job *ui;
};

#endif // CHANGE_JOB_H

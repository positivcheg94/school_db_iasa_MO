#ifndef ADD_SCHEDULE_ENTRY_H
#define ADD_SCHEDULE_ENTRY_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>

#include <QSqlQueryModel>
//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class add_schedule_entry;
}

class add_schedule_entry : public QWidget
{
    Q_OBJECT

public:
    explicit add_schedule_entry(QWidget *parent = 0);
    ~add_schedule_entry();
    void show_add_schedule_entry();
    void load_teachers_by_subj();
    void reload_current_schedule();

private slots:
    void on_add_button_clicked();

    void on_class_select_currentIndexChanged(int index);

    void on_day_of_week_currentIndexChanged(int index);

    void on_subject_select_currentIndexChanged(int index);

private:
    Ui::add_schedule_entry *ui;
};

#endif // ADD_SCHEDULE_ENTRY_H

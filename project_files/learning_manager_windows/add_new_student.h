#ifndef ADD_NEW_STUDENT_H
#define ADD_NEW_STUDENT_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>

//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class add_new_student;
}

class add_new_student : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_student(QWidget *parent = 0);
    ~add_new_student();
signals:
    void restore_main_menu();
private slots:
    void on_submit_button_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Ui::add_new_student *ui;
};

#endif // ADD_NEW_STUDENT_H

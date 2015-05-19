#ifndef ADD_NEW_SUBJECT_H
#define ADD_NEW_SUBJECT_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>

//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class add_new_subject;
}

class add_new_subject : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_subject(QWidget *parent = 0);
    ~add_new_subject();


    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void on_submit_new_subject_button_clicked();

private:
    Ui::add_new_subject *ui;
};

#endif // ADD_NEW_SUBJECT_H

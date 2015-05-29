#ifndef ASSIGN_PUPIL_TO_CLASS_H
#define ASSIGN_PUPIL_TO_CLASS_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>

#include <QSqlQueryModel>
//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class assign_pupil_to_class;
}

class assign_pupil_to_class : public QWidget
{
    Q_OBJECT

public:
    explicit assign_pupil_to_class(QWidget *parent = 0);
    ~assign_pupil_to_class();
    void show_assign_pupil_to_class_dialog();
signals:
    void restore_main_menu();
private slots:
    void on_submit_button_clicked();

private:
    Ui::assign_pupil_to_class *ui;
};

#endif // ASSIGN_PUPIL_TO_CLASS_H

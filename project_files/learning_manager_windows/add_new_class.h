#ifndef ADD_NEW_CLASS_H
#define ADD_NEW_CLASS_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>

//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class add_new_class;
}

class add_new_class : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_class(QWidget *parent = 0);
    ~add_new_class();
signals:
    void restore_main_menu();
private slots:
    void on_submit_button_clicked();

private:
    Ui::add_new_class *ui;
};

#endif // ADD_NEW_CLASS_H

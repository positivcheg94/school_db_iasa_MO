#ifndef EXPIRE_POSITION_H
#define EXPIRE_POSITION_H

#include <QWidget>
#include <QDate>
#include <QCloseEvent>

#include <QSqlQuery>
#include <QSqlQueryModel>

//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class expire_position;
}

class expire_position : public QWidget
{
    Q_OBJECT

public:
    explicit expire_position(QWidget *parent = 0);
    ~expire_position();

    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void show_expire_position_dialog(QSqlQueryModel* model);
    void on_submit_button_clicked();

private:
    Ui::expire_position *ui;
};

#endif // EXPIRE_POSITION_H

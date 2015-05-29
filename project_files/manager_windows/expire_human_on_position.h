#ifndef EXPIRE_HUMAN_ON_POSITION_H
#define EXPIRE_HUMAN_ON_POSITION_H

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
class expire_human_on_position;
}

class expire_human_on_position : public QWidget
{
    Q_OBJECT

public:
    explicit expire_human_on_position(QWidget *parent = 0);
    ~expire_human_on_position();

    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void show_expire_human_on_position_dialog();

    void on_submit_button_clicked();

    void on_human_picker_currentIndexChanged(int index);

private:
    Ui::expire_human_on_position *ui;
};

#endif // EXPIRE_HUMAN_ON_POSITION_H

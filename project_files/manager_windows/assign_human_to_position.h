#ifndef ASSIGN_HUMAN_TO_POSITION_H
#define ASSIGN_HUMAN_TO_POSITION_H

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
class assign_human_to_position;
}

class assign_human_to_position : public QWidget
{
    Q_OBJECT

public:
    explicit assign_human_to_position(QWidget *parent = 0);
    ~assign_human_to_position();

    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void show_assign_human_to_position_dialog();

    void on_submit_button_clicked();

    void on_end_date_is_active_stateChanged(int state);

private:
    Ui::assign_human_to_position *ui;
};

#endif // ASSIGN_HUMAN_TO_POSITION_H

#ifndef ADMINISTRATE_POSITION_H
#define ADMINISTRATE_POSITION_H

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
class administrate_position;
}

class administrate_position : public QWidget
{
    Q_OBJECT

public:
    explicit administrate_position(QWidget *parent = 0);
    ~administrate_position();
    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void show_administrating_positions_dialog();

    void on_submit_button_clicked();

private:
    Ui::administrate_position *ui;
};

#endif // ADMINISTRATE_POSITION_H

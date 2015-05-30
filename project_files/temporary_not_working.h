#ifndef TEMPORARY_NOT_WORKING_H
#define TEMPORARY_NOT_WORKING_H

#include <QWidget>
#include <QDialog>
#include <QCloseEvent>
#include <QComboBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "temporary_not_working_windows/ill_widget.h"
#include "temporary_not_working_windows/conferention_widget.h"
#include "temporary_not_working_windows/another_reason_widget.h"

namespace Ui {
class temporary_not_working;
}

class temporary_not_working : public QDialog
{
    Q_OBJECT

public:
    explicit temporary_not_working(QWidget *parent = 0, int s_id=0);
    ~temporary_not_working();

    void closeEvent(QCloseEvent * event);

private slots:

    void on_submit_button_clicked();

public:
    int id_reason;
    QString start;
    QString end;
    QString field1;
    QString field2;
    QString field3;
    int staff_id;
private:
    Ui::temporary_not_working *ui;
    ill_widget ill_wget;
    conferention_widget conferention_wget;
    another_reason_widget another_reason_wget;
};

#endif // TEMPORARY_NOT_WORKING_H

#ifndef ADD_MARKS_H
#define ADD_MARKS_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>
#include <QSqlQueryModel>
//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>


namespace Ui {
class add_marks;
}

class add_marks : public QWidget
{
    Q_OBJECT

public:
    explicit add_marks(QWidget *parent = 0, int staff_id = 0);
    ~add_marks();
    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void on_cbSubjects_currentIndexChanged(int index);

    void on_cbClasses_currentIndexChanged(int index);
    
private:
    Ui::add_marks *ui;
};

#endif // ADD_MARKS_H

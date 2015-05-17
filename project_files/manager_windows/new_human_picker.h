#ifndef NEW_HUMAN_PICKER_H
#define NEW_HUMAN_PICKER_H

#include <QWidget>
#include <QCloseEvent>

#include <QSqlQuery>

//debug stuff
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class new_human_picker;
}

class new_human_picker : public QWidget
{
    Q_OBJECT

public:
    explicit new_human_picker(QWidget *parent = 0);
    ~new_human_picker();

    void closeEvent (QCloseEvent *event);

signals:
    void restore_main_menu();

private slots:
    void on_submit_button_clicked();

private:
    Ui::new_human_picker *ui;
};

#endif // NEW_HUMAN_PICKER_H

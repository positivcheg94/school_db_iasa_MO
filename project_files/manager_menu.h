#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include "manager_windows/new_human_picker.h"

#include "menu_base.h" //which is actually QMainWindow
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class manager_menu;
}

class manager_menu : public menu_base
{
    Q_OBJECT

public:
    explicit manager_menu(QWidget *parent = 0);
    virtual ~manager_menu();

private slots:
    virtual void restore_menu();
    void on_add_new_human_clicked();

    void on_show_humans_clicked();

private:
    Ui::manager_menu *ui;
    new_human_picker* n_human_picker;
};

#endif // MANAGER_MENU_H

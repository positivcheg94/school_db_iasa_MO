#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include "manager_windows/new_human_picker.h"

#include <QMainWindow>

#include <QSqlDatabase>

namespace Ui {
class manager_menu;
}

class manager_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager_menu(QWidget *parent = 0);
    ~manager_menu();

private slots:
    void restore_manager_menu();
    void on_add_new_human_clicked();

    void on_show_humans_clicked();

private:
    Ui::manager_menu *ui;
    new_human_picker* n_human_picker;
};

#endif // MANAGER_MENU_H

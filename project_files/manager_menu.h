#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include <QMainWindow>

namespace Ui {
class manager_menu;
}

class manager_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager_menu(QWidget *parent = 0);
    ~manager_menu();

private:
    Ui::manager_menu *ui;
};

#endif // MANAGER_MENU_H

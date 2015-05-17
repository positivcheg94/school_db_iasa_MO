#ifndef STUDENT_MENU_H
#define STUDENT_MENU_H

#include <QMainWindow>

namespace Ui {
class student_menu;
}

class student_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit student_menu(QWidget *parent = 0);
    ~student_menu();

private:
    Ui::student_menu *ui;
};

#endif // STUDENT_MENU_H

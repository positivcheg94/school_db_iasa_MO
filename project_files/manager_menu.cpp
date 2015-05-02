#include "manager_menu.h"
#include "ui_manager_menu.h"

manager_menu::manager_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager_menu)
{
    ui->setupUi(this);
}

manager_menu::~manager_menu()
{
    delete ui;
}

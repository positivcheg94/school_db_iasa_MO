#include "student_menu.h"
#include "ui_student_menu.h"

student_menu::student_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student_menu)
{
    ui->setupUi(this);
}

student_menu::~student_menu()
{
    delete ui;
}

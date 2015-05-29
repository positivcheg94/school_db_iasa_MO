#include "learning_manager_menu.h"
#include "ui_learningmanagermenu.h"

learning_manager_menu::learning_manager_menu(QWidget *parent) :
    menu_base(parent),
    ui(new Ui::LearningManagerMenu)
{
    ui->setupUi(this);
}

learning_manager_menu::~learning_manager_menu()
{
    delete ui;
}

void learning_manager_menu::restore_menu()
{
    this->show();
}

void learning_manager_menu::closeEvent (QCloseEvent *event) {
    event->ignore();
    emit restore_main_menu();
}

void learning_manager_menu::on_addPupil_clicked()
{

}

void learning_manager_menu::on_addPupilToClass_clicked()
{

}

void learning_manager_menu::on_addClass_clicked()
{

}

void learning_manager_menu::on_view_classes_clicked()
{

}

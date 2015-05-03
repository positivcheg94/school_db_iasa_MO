#include "manager_menu.h"
#include "ui_manager_menu.h"

manager_menu::manager_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager_menu)
{
    ui->setupUi(this);
    n_human_picker = new new_human_picker();

    //connects
    connect(n_human_picker,SIGNAL(restore_main_menu()),this,SLOT(restore_manager_menu()));
}

manager_menu::~manager_menu()
{
    delete ui;
}


//slots
void manager_menu::restore_manager_menu()
{
    this->show();
}

void manager_menu::on_add_new_human_clicked()
{
    this->hide();
    this->n_human_picker->show();
}

void manager_menu::on_show_humans_clicked()
{
    emit open_main_window("people_workers");
    this->hide();

}

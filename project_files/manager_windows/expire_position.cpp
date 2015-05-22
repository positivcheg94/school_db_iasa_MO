#include "expire_position.h"
#include "ui_expire_position.h"

expire_position::expire_position(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expire_position)
{
    ui->setupUi(this);
}

expire_position::~expire_position()
{
    delete ui;
}

void expire_position::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->position_picker->model()->deleteLater();

    emit restore_main_menu();
    this->hide();
}

void expire_position::on_submit_button_clicked()
{

}

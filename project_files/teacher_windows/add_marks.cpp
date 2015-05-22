#include "add_marks.h"
#include "ui_add_marks.h"

add_marks::add_marks(QWidget *parent, int staff_id) :
    QWidget(parent),
    ui(new Ui::add_marks)
{
    ui->setupUi(this);


}

add_marks::~add_marks()
{
    delete ui;
}

void add_marks::closeEvent(QCloseEvent *event) {
    event->ignore();
    emit restore_main_menu();
    this->hide();
}

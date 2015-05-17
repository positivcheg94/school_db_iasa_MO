#include "add_new_subject.h"
#include "ui_add_new_subject.h"

add_new_subject::add_new_subject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_new_subject)
{
    ui->setupUi(this);
}

add_new_subject::~add_new_subject()
{
    delete ui;
}

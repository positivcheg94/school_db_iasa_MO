#include "add_new_job.h"
#include "ui_add_new_job.h"

add_new_job::add_new_job(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_new_job)
{
    ui->setupUi(this);
}

add_new_job::~add_new_job()
{
    delete ui;
}

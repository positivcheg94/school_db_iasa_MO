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

void add_new_job::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->subject_picker->model()->deleteLater();
    emit restore_main_menu();
    this->hide();
}

void add_new_job::show_add_new_job_dialog(QSqlQueryModel* model)
{
    this->ui->subject_picker->setModel(model);
    this->show();
}

void add_new_job::on_submit_new_position_button_clicked()
{
    int picked_index = this->ui->subject_picker->currentIndex();
    this->ui->subject_picker->
}

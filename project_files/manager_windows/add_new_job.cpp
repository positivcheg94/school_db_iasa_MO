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
    this->ui->position_name_edit->clear();
    this->ui->is_teacher_checkbox->setCheckState(Qt::Unchecked);
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
    QString subject_name = this->ui->position_name_edit->text();
    int picked_index = this->ui->subject_picker->currentIndex();

    QSqlQuery query;
    query.prepare("insert into positions(position_name,id_subject) values(?,?)");
    query.addBindValue(subject_name);

    if(this->ui->is_teacher_checkbox->checkState() == Qt::Unchecked)
        query.addBindValue(QVariant(QVariant::Int));
    else
        query.addBindValue(this->ui->subject_picker->model()->index(picked_index,1).data().toInt());

    query.exec();

    //error
    QMessageBox msg;
    if (query.lastError().type()!=QSqlError::NoError){
        msg.setText(query.lastError().text());
        msg.exec();
        return;
    }
    else{
        msg.setText("Rows affected - "+QString::number(query.numRowsAffected()));
        msg.exec();
    }

    this->ui->position_name_edit->clear();
    this->ui->is_teacher_checkbox->setCheckState(Qt::Unchecked);
    this->ui->subject_picker->model()->deleteLater();

    emit restore_main_menu();
    this->hide();
}

void add_new_job::on_is_teacher_checkbox_stateChanged(int state)
{
    if(state == Qt::Unchecked)
        this->ui->subject_picker->setDisabled(true);
    else
        this->ui->subject_picker->setDisabled(false);
}

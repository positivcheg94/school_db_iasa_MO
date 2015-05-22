#include "change_job.h"
#include "ui_change_job.h"

change_job::change_job(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_job)
{
    ui->setupUi(this);
}

change_job::~change_job()
{
    delete ui;
}

void change_job::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->pick_position_combobox->model()->deleteLater();
    this->ui->subject_picker->model()->deleteLater();

    this->ui->position_name_edit->clear();
    this->ui->is_teacher_checkbox->setCheckState(Qt::Unchecked);
    emit restore_main_menu();
    this->hide();
}

void change_job::show_change_job_dialog(QSqlQueryModel* model,QSqlQueryModel* model_subj)
{
    this->ui->pick_position_combobox->setModel(model);
    this->ui->subject_picker->setModel(model_subj);
    this->show();
}

void change_job::on_is_teacher_checkbox_stateChanged(int state)
{
    if(state == Qt::Unchecked)
        this->ui->subject_picker->setDisabled(true);
    else
        this->ui->subject_picker->setDisabled(false);
}

void change_job::on_submit_position_button_clicked()
{
    QString position_name = this->ui->position_name_edit->text();
    int position_index = this->ui->pick_position_combobox->currentIndex();
    int subject_index = this->ui->subject_picker->currentIndex();

    QSqlQuery query;
    query.prepare("update positions set position_name=?,id_subject=? where id_position=?");
    query.addBindValue(position_name);

    if(this->ui->is_teacher_checkbox->checkState() == Qt::Unchecked)
        query.addBindValue(QVariant(QVariant::Int));
    else
        query.addBindValue(this->ui->subject_picker->model()->index(subject_index,1).data().toInt());

    query.addBindValue(this->ui->pick_position_combobox->model()->index(position_index,2).data().toInt());

    query.exec();

    //error
    if (query.lastError().type()!=QSqlError::NoError){
        QMessageBox msg;
        msg.setText(query.lastError().text());
        msg.exec();
        return;
    }

    this->ui->position_name_edit->clear();
    this->ui->is_teacher_checkbox->setCheckState(Qt::Unchecked);
    this->ui->pick_position_combobox->model()->deleteLater();
    this->ui->subject_picker->model()->deleteLater();

    emit restore_main_menu();
    this->hide();
}

void change_job::on_pick_position_combobox_currentIndexChanged(int index)
{
    this->ui->position_name_edit->clear();
    this->ui->position_name_edit->insert(this->ui->pick_position_combobox->model()->index(index,0).data().toString());
}

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

void add_new_subject::closeEvent(QCloseEvent *event) {
    event->ignore();
    emit restore_main_menu();
    this->hide();
}

void add_new_subject::on_submit_new_subject_button_clicked()
{
    QSqlQuery query;
    QString subject_name = this->ui->subject_name_edit->text();
    QString hours_quantity = this->ui->hours_quantity_edit->text();
    QString study_programe = this->ui->study_programe_edit->toPlainText();

    query.prepare("insert into subjects(subject_name,hours_quantity,study_programe) values(?,?,?)");
    query.addBindValue(subject_name);
    query.addBindValue(hours_quantity.toInt());
    query.addBindValue(study_programe);
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

    emit restore_main_menu();
    this->hide();
    this->ui->subject_name_edit->clear();
    this->ui->hours_quantity_edit->clear();
    this->ui->study_programe_edit->clear();
}

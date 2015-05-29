#include "add_new_student.h"
#include "ui_add_new_student.h"

add_new_student::add_new_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_new_student)
{
    ui->setupUi(this);
}

add_new_student::~add_new_student()
{
    delete ui;
}

void add_new_student::closeEvent(QCloseEvent *event) {
    event->ignore();
    emit restore_main_menu();
    this->hide();
}
void add_new_student::on_submit_button_clicked()
{
    QSqlQuery query;
    QString name = this->ui->name->text();
    QString surname = this->ui->surname->text();
    QString patronymic = this->ui->patronymic->text();
    QString birthdate = this->ui->birthdate->text();

    query.prepare("insert into schoolers(first_name,last_name,patronim,birth_date) values(?,?,?,?)");
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(patronymic);
    query.addBindValue(birthdate);
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
    this->ui->name->clear();
    this->ui->surname->clear();
    this->ui->patronymic->clear();
    this->ui->birthdate->clear();
}

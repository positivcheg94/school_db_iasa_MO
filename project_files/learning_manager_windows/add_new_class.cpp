#include "add_new_class.h"
#include "ui_add_new_class.h"

add_new_class::add_new_class(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_new_class)
{
    ui->setupUi(this);
}

add_new_class::~add_new_class()
{
    delete ui;
}

void add_new_class::on_submit_button_clicked()
{
    QSqlQuery query;
    QString creation_date = this->ui->creation_year->text() + "-09-01";
    QString letter = this->ui->letter->text();


    query.prepare("insert into classes(creation_date,letter) values(?,?)");
    query.addBindValue(creation_date);
    query.addBindValue(letter);
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
    this->ui->creation_year->setDate(QDate::currentDate());
    this->ui->letter->clear();
}

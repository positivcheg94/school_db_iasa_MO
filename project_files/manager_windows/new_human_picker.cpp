#include "new_human_picker.h"
#include "ui_new_human_picker.h"

new_human_picker::new_human_picker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_human_picker)
{
    ui->setupUi(this);
}

new_human_picker::~new_human_picker()
{
    delete ui;
}

void new_human_picker::on_submit_button_clicked()
{
    QSqlQuery query;
    QString name = this->ui->name->text();
    QString surname = this->ui->surname->text();
    QString patronymic = this->ui->patronymic->text();
    QString phone = this->ui->phone->text();
    QString passport = this->ui->passport->text();
    QString code = this->ui->code->text();


    QString str_query = "select * from people_workers where code='"+code+"' and passport='"+passport+"'";
    query.exec(str_query);
    if(!query.isActive()){
        qDebug()<<"error";
        qDebug()<<query.lastQuery();
        qDebug()<<query.lastError();
    }
    if(query.size()==0){
        query.prepare("insert into people_workers(first_name,last_name,patronymic,tel_num,passport,code) values(?,?,?,?,?,?)");
        query.addBindValue(name);
        query.addBindValue(surname);
        query.addBindValue(patronymic);
        query.addBindValue(phone);
        query.addBindValue(passport);
        query.addBindValue(code);
        query.exec();
        qDebug()<<query.lastQuery();
        if (query.lastError().type()!=QSqlError::NoError) qDebug()<<query.lastError().text();
    }
    this->hide();
    this->ui->name->clear();
    this->ui->surname->clear();
    this->ui->patronymic->clear();
    this->ui->phone->clear();
    this->ui->passport->clear();
    this->ui->code->clear();
    emit restore_main_menu();
}

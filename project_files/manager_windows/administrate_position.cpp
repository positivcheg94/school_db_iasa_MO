#include "administrate_position.h"
#include "ui_administrate_position.h"

administrate_position::administrate_position(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrate_position)
{
    ui->setupUi(this);
    this->ui->start_date->setDate(QDate::currentDate());
}

administrate_position::~administrate_position()
{
    delete ui;
}

void administrate_position::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->position_picker->model()->deleteLater();
    this->ui->salary->clear();
    this->ui->position_quantity->clear();
    this->ui->start_date->setDate(QDate::currentDate());
    emit restore_main_menu();
    this->hide();
}

void administrate_position::show_administrating_positions_dialog(QSqlQueryModel* model){
    this->ui->position_picker->setModel(model);
    this->show();
}


void administrate_position::on_submit_button_clicked()
{
    int id_position = this->ui->position_picker->model()->index(this->ui->position_picker->currentIndex(),1).data().toInt();
    int salary = this->ui->salary->text().toInt();
    int position_quantity = this->ui->position_quantity->text().toInt();
    QString date = this->ui->start_date->text();

    QSqlQuery query;
    query.prepare("insert into administrating_positions(id_position,salary,position_quantity,start_date,end_date) values(?,?,?,?,?)");
    query.addBindValue(id_position);
    query.addBindValue(salary);
    query.addBindValue(position_quantity);
    query.addBindValue(date);
    query.addBindValue(QVariant(QVariant::Date));
    query.exec();

    qDebug() << query.numRowsAffected();

    //error
//    if (query.lastError().type()!=QSqlError::NoError){
        QMessageBox msg;
        msg.setText(query.lastError().text());
        msg.exec();
//        return;
//    }

    this->ui->position_picker->model()->deleteLater();
    this->ui->salary->clear();
    this->ui->position_quantity->clear();
    this->ui->start_date->setDate(QDate::currentDate());
    emit restore_main_menu();
    this->hide();
}

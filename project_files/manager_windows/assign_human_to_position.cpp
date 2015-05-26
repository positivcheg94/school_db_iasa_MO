#include "assign_human_to_position.h"
#include "ui_assign_human_to_position.h"

assign_human_to_position::assign_human_to_position(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assign_human_to_position)
{
    ui->setupUi(this);
    this->ui->start_date->setDate(QDate::currentDate());
}

assign_human_to_position::~assign_human_to_position()
{
    delete ui;
}

void assign_human_to_position::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->human_picker->model()->deleteLater();
    this->ui->position_picker->model()->deleteLater();
    this->ui->incentive->clear();
    this->ui->start_date->setDate(QDate::currentDate());
    emit restore_main_menu();
    this->hide();
}

void assign_human_to_position::show_assign_human_to_position_dialog(QSqlQueryModel* humans_model, QSqlQueryModel* positions_model)
{
    this->ui->human_picker->setModel(humans_model);
    this->ui->position_picker->setModel(positions_model);
    this->show();
}

void assign_human_to_position::on_submit_button_clicked()
{
    int id_human = this->ui->human_picker->model()->index(this->ui->human_picker->currentIndex(),1).data().toInt();
    int id_position = this->ui->position_picker->model()->index(this->ui->position_picker->currentIndex(),1).data().toInt();
    int incentive = this->ui->incentive->text().toInt();
    QString date = this->ui->start_date->text();


    QSqlQuery query;
    query.prepare("insert into personnel(id_human,id_position,incentive,start_working_date,end_working_date) values(?,?,?,?,?)");
    query.addBindValue(id_human);
    query.addBindValue(id_position);
    query.addBindValue(incentive);
    query.addBindValue(date);
    query.addBindValue(QVariant(QVariant::Date));
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

    this->ui->human_picker->model()->deleteLater();
    this->ui->position_picker->model()->deleteLater();
    this->ui->incentive->clear();
    this->ui->start_date->setDate(QDate::currentDate());
    emit restore_main_menu();
    this->hide();
}

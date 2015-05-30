#include "expire_human_on_position.h"
#include "ui_expire_human_on_position.h"

expire_human_on_position::expire_human_on_position(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expire_human_on_position)
{
    ui->setupUi(this);
}

expire_human_on_position::~expire_human_on_position()
{
    delete ui;
}

void expire_human_on_position::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->human_picker->model()->deleteLater();
    this->ui->position_picker->model()->deleteLater();
    emit restore_main_menu();
    this->hide();
}

void expire_human_on_position::show_expire_human_on_position_dialog(){
    QSqlQuery query("select pw.first_name||' '||pw.last_name||' '||pw.patronymic||' - '||pw.passport,cw.id_human from currently_working cw join people_workers pw on cw.id_human=pw.id_human");
    QSqlQueryModel* human_model = new QSqlQueryModel();
    human_model->setQuery(query);
    this->ui->human_picker->setModel(human_model);
    if (query.size()>0)
        emit this->ui->human_picker->setCurrentIndex(0);
    this->show();
}

void expire_human_on_position::on_human_picker_currentIndexChanged(int index)
{
    if(this->ui->position_picker->model())
        delete this->ui->position_picker->model();
    QSqlQuery query;
    query.prepare("select p.position_name,cw.id_personnel from currently_working cw join positions p on cw.id_position=p.id_position and cw.id_human=?");
    query.addBindValue(this->ui->human_picker->model()->index(index,1).data().toInt());
    query.exec();
    QSqlQueryModel* new_position_model = new QSqlQueryModel();
    new_position_model->setQuery(query);
    this->ui->position_picker->setModel(new_position_model);
}

void expire_human_on_position::on_submit_button_clicked()
{
//    this->ui->pick_position_combobox->model()->index(position_index,2).data().toInt()
    QSqlQuery query;
    query.prepare("update personnel set end_date=current_date where id_personnel=?");
    query.addBindValue(this->ui->position_picker->model()->index(this->ui->position_picker->currentIndex(),1).data().toInt());
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
    emit restore_main_menu();
    this->hide();
}

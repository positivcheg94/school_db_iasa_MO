#include "expire_position.h"
#include "ui_expire_position.h"

expire_position::expire_position(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expire_position)
{
    ui->setupUi(this);
}

expire_position::~expire_position()
{
    delete ui;
}

void expire_position::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->ui->position_picker->model()->deleteLater();
    emit restore_main_menu();
    this->hide();
}

void expire_position::show_expire_position_dialog(){
    QSqlQuery query("select position_name,id_administrating_position,pos.id_position from positions pos join administrating_positions adm_pos on pos.id_position=adm_pos.id_position and adm_pos.end_date is null order by position_name asc");
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    this->ui->position_picker->setModel(model);
    this->show();
}

void expire_position::on_submit_button_clicked()
{
    int picked_index = this->ui->position_picker->currentIndex();
    int id_administrating_position = this->ui->position_picker->model()->index(picked_index,1).data().toInt();
    QDate date = QDate::currentDate();
    QSqlQuery query;
    query.prepare("update administrating_positions set end_date=? where id_administrating_position=?");
    query.addBindValue(date.toString("yyyy-M-d"));
    query.addBindValue(id_administrating_position);
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

    this->ui->position_picker->model()->deleteLater();
    emit restore_main_menu();
    this->hide();
}

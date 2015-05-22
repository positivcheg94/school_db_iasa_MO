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

void expire_position::show_expire_position_dialog(QSqlQueryModel* model){
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
    if (query.lastError().type()!=QSqlError::NoError){
        QMessageBox msg;
        msg.setText(query.lastError().text());
        msg.exec();
        return;
    }

    this->ui->position_picker->model()->deleteLater();
    emit restore_main_menu();
    this->hide();
}

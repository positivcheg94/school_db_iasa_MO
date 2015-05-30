#include "temporary_not_working.h"
#include "ui_temporary_not_working.h"

temporary_not_working::temporary_not_working(QWidget *parent, int s_id) :
    QDialog(parent),
    ui(new Ui::temporary_not_working)
{
    ui->setupUi(this);

    ui->reason_stack->addWidget(dynamic_cast<QWidget*>(&this->ill_wget));
    ui->reason_stack->addWidget(dynamic_cast<QWidget*>(&this->conferention_wget));
    ui->reason_stack->addWidget(dynamic_cast<QWidget*>(&this->another_reason_wget));
    connect(this->ui->reason_picker, SIGNAL(activated(int)), this->ui->reason_stack, SLOT(setCurrentIndex(int)));
    staff_id=s_id;
}

temporary_not_working::~temporary_not_working()
{
    delete ui;
}

void temporary_not_working::closeEvent(QCloseEvent* event)
{
    event->ignore();
    this->reject();
}

void temporary_not_working::on_submit_button_clicked()
{
    int index = this->ui->reason_picker->currentIndex();
    id_reason = index;
    start = this->ui->dateEdit->text();
    end = this->ui->dateEdit_2->text();
    QString table_name;
    switch (index) {
    case 0:
        field1 = this->ill_wget.get_first();
        table_name="ill";
        break;
    case 1:
        field1 = this->conferention_wget.get_first();
        field2 = this->conferention_wget.get_second();
        field3 = this->conferention_wget.get_third();
        table_name="conferention";
        break;
    case 2:
        field1 = this->another_reason_wget.get_first();
        field2 = this->another_reason_wget.get_second();
        table_name="another_reason";
        break;
    default:
        return;
        break;
    }

    QSqlQuery q_pers;
    q_pers.prepare("SELECT distinct on (id_human, id_position) id_personnel "
                   "FROM personnel "
                   "where id_human=? "
                   "ORDER BY id_human, id_position, end_date desc");
    q_pers.addBindValue(staff_id);
    q_pers.exec();
    int pers_id;
            QSqlQuery query;
    while(q_pers.next()) {
        pers_id=q_pers.value(0).toInt();
        query.prepare("insert into temporary_not_working(start_date,end_date,id_personnel) values(?,?,?)");
        query.addBindValue(start);
        query.addBindValue(end);
        query.addBindValue(pers_id);
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
        int tnw_id=query.lastInsertId().toInt();

        QString additional_reason("insert into "+table_name+" values(?,?");
        if(index>0) additional_reason += ",?";
        if(index==1) additional_reason += ",?";
        additional_reason += ")";
        query.prepare(additional_reason);
        query.addBindValue(tnw_id);
        query.addBindValue(field1);
        if(index>0) query.addBindValue(field2);
        if(index==1) query.addBindValue(field3);
        query.exec();

        if (query.lastError().type()!=QSqlError::NoError){
            msg.setText(query.lastError().text());
            msg.exec();
            return;
        }
        else{
            msg.setText("Rows affected - "+QString::number(query.numRowsAffected()));
            msg.exec();
        }
    }
    this->accept();


}

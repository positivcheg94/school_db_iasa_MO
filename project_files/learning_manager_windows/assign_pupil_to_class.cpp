#include "assign_pupil_to_class.h"
#include "ui_assign_pupil_to_class.h"

assign_pupil_to_class::assign_pupil_to_class(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assign_pupil_to_class)
{
    ui->setupUi(this);
}

assign_pupil_to_class::~assign_pupil_to_class()
{
    delete ui;
}

void assign_pupil_to_class::show_assign_pupil_to_class_dialog() {
    QSqlQuery pupils_query("select last_name || ' ' || first_name || ' ' || patronim as ПІБ, id_pupil from ("
                      "select distinct on(s.id_pupil) s.*, a_s.id_class, a_s.date from schoolers s"
                      " LEFT JOIN admission_schoolers a_s "
                      "on s.id_pupil=a_s.id_pupil "
                      "order by s.id_pupil, date desc"
                  ") a"
                  " order by id_class desc");
    QSqlQueryModel* pupils_model = new QSqlQueryModel();
    pupils_model->setQuery(pupils_query);
    QSqlQuery query_classes("select class_num(creation_date)||letter,id_class from classes where class_num(creation_date) <=12");
    QSqlQueryModel* classes_model = new QSqlQueryModel();
    classes_model->setQuery(query_classes);
    this->ui->pupil->setModel(pupils_model);
    this->ui->class_select->setModel(classes_model);
    this->show();
}

void assign_pupil_to_class::on_submit_button_clicked()
{
    int id_pupil = this->ui->pupil->model()->index(this->ui->pupil->currentIndex(),1).data().toInt();
    int id_class = this->ui->class_select->model()->index(this->ui->class_select->currentIndex(),1).data().toInt();

    QSqlQuery query;
    query.prepare("insert into admission_schoolers(id_pupil,id_class,date) values(?,?,current_date)");
    query.addBindValue(id_pupil);
    query.addBindValue(id_class);
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

    this->ui->pupil->model()->deleteLater();
    this->ui->class_select->model()->deleteLater();
    emit restore_main_menu();
    this->hide();
}
